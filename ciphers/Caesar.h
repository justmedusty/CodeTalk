//
// Created by dustyn on 11/27/26.
//

#ifndef CODETALK_CAESAR_H
#define CODETALK_CAESAR_H
#include "Cipher.h"

class CaesarCipher : public Cipher {
public:
    explicit CaesarCipher(const std::string &pathToCipherFile)
        : Cipher(pathToCipherFile) {
    }

    std::string encrypt(std::string plaintext) override {
        uint32_t shift = this->key.key_material[0];
        auto result = std::string(plaintext.length(), 0);

        for (uint32_t i = 0; i < plaintext.length(); i++) {
            result[i] = CHARACTER_MAP[getCharacterPosition(&plaintext[i]) + shift];
        }

        return result;
    }

    std::string decrypt(std::string ciphertext) override {
        uint32_t shift = this->key.key_material[0];
        auto result = std::string(ciphertext.length(), 0);


        for (uint32_t i = 0; i < ciphertext.length(); i++) {
            result[i] = CHARACTER_MAP[getCharacterPosition(&ciphertext[i]) - shift];
        }

        return result;
    }
};

#endif //CODETALK_CAESAR_H
