//
// Created by dustyn on 11/27/26.
//

#ifndef CODETALK_CAESAR_H
#define CODETALK_CAESAR_H
#include "Cipher.h"

class CaesarCipher : public Cipher {
public:
    std::string encrypt(std::string &plaintext) override {
        if (this->key.key_material.has_value()) {
            uint32_t shift = this->key.key_material.value()[0];
            auto result = std::string(plaintext.length(), 0);

            for (uint32_t i = 0; i < plaintext.length(); i++) {
                result[i] = CHARACTER_MAP[(getCharacterPosition(&plaintext[i]) + shift) % CHARACTER_MAP_LENGTH];
            }

            return result;
        }

        emitMessage(FATAL, "CaesarCipher::encrypt(): Invalid key type or key not set!");
        exit(EXIT_CODES::KEY_INVALID);
    }

    std::string decrypt(std::string &ciphertext) override {
        if (this->key.key_material.has_value()) {
            uint32_t shift = this->key.key_material.value()[0];
            auto result = std::string(ciphertext.length(), 0);


            for (uint32_t i = 0; i < ciphertext.length(); i++) {
                result[i] = CHARACTER_MAP[getCharacterPosition((&ciphertext[i]) + (CHARACTER_MAP_LENGTH - shift)) %
                                          CHARACTER_MAP_LENGTH];
            }

            return result;
        }
        emitMessage(FATAL, "CaesarCipher::decrypt(): Invalid key type or key not set!");
        exit(EXIT_CODES::KEY_INVALID);
    }

    void parseKey(std::string &key) override {
        uint64_t shift_key = 0;
        if ((shift_key = std::strtol(key.c_str(), reinterpret_cast<char **>((uint64_t) (key.c_str() + key.length())),
                                     10) < 0)) {
            emitMessage(FATAL, std::format("Caesar.h parseKey(): Could not parse key {}", key));
            exit(EXIT_CODES::KEY_INVALID);
        }

        if (shift_key < CHARACTER_MAP_LENGTH) {
            emitMessage(FATAL, std::format("Caesar.h parseKey(): Invalid shift key {}", shift_key));
            exit(EXIT_CODES::KEY_INVALID);
        }

        if (this->key.key_material.has_value()) {
            this->key.key_material.value().push_back(shift_key);
        } else {
            emitMessage(FATAL, "CaesarCipher::parseKey(): Invalid key type or key not set!");
            exit(EXIT_CODES::KEY_INVALID);
        }
    }
};

#endif //CODETALK_CAESAR_H
