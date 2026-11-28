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

    std::string encrypt(std::string& plaintext) override {
        if (this->key.key_material.value().size() < plaintext.length()) {
            emitMessage(FATAL, "OneTimePadCipher::encrypt() : Key length is too small! Key length must be at least as long as the message!");
            exit(EXIT_CODES::KEY_INVALID);
        }
        std::string encrypted = std::string(plaintext.length(), '0');

        for (size_t i = 0; i < plaintext.length(); i++) {
            encrypted[i] = CHARACTER_MAP[(getCharacterPosition(&plaintext[i]) + this->key.key_material.value()[i]) % CHARACTER_MAP_LENGTH];
        }
    }

    std::string decrypt(std::string& ciphertext) override {

        if (!this->key.key_material.has_value()) {
            emitMessage(FATAL,"OneTimePadCipher::decrypt() : Key not found!");
            exit(EXIT_CODES::KEY_INVALID);
        }

        if (this->key.key_material.value().size() < ciphertext.length()) {
            emitMessage(FATAL, "OneTimePadCipher::encrypt() : Key length is too small! Key length must be at least as long as the message!");
            exit(EXIT_CODES::KEY_INVALID);
        }

        std::string plaintext = std::string(ciphertext.length(), '0');

        for (size_t i = 0; i < plaintext.length(); i++) {
            plaintext[i] = CHARACTER_MAP[(getCharacterPosition(&ciphertext[i]) + (CHARACTER_MAP_LENGTH - this->key.key_material.value()[i])) % CHARACTER_MAP_LENGTH];
        }

    }

    void parseKey(std::string &key) override {
        return;
    }
};

#endif //CODETALK_ONETIMEPAD_H
