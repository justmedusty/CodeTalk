//
// Created by dustyn on 11/28/26.
//

#ifndef CODETALK_ONETIMEPAD_H
#define CODETALK_ONETIMEPAD_H
#include <string>

#include "Cipher.h"
#include "../CodeTalk.h"
#include "../cli/CommandLineTools.h"
class OneTimePadCipher : public Cipher {
public:

    std::string encrypt(std::string plaintext) override {
        if (this->key.key_material.size() < plaintext.length()) {
            emitMessage(FATAL, "OneTimePadCipher::encrypt() : Key length is too small! Key length must be at least as long as the message!");
            exit(EXIT_CODES::KEY_INVALID);
        }
        std::string encrypted = std::string(plaintext.length(), '0');

        for (size_t i = 0; i < plaintext.length(); i++) {
            encrypted[i] = CHARACTER_MAP[(getCharacterPosition(&plaintext[i]) + this->key.key_material[i]) % CHARACTER_MAP_LENGTH];
        }
    }

    std::string decrypt(std::string ciphertext) override {
        if (this->key.key_material.size() < ciphertext.length()) {
            emitMessage(FATAL, "OneTimePadCipher::encrypt() : Key length is too small! Key length must be at least as long as the message!");
            exit(EXIT_CODES::KEY_INVALID);
        }

        std::string plaintext = std::string(ciphertext.length(), '0');

        for (size_t i = 0; i < plaintext.length(); i++) {
            plaintext[i] = CHARACTER_MAP[(getCharacterPosition(&ciphertext[i]) + (CHARACTER_MAP_LENGTH - this->key.key_material[i])) % CHARACTER_MAP_LENGTH];
        }

    }
};

#endif //CODETALK_ONETIMEPAD_H
