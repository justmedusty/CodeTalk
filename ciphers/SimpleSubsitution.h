//
// Created by dustyn on 11/28/26.
//

#ifndef CODETALK_SIMPLESUBSITUTION_H
#define CODETALK_SIMPLESUBSITUTION_H
#include "Cipher.h"

class SimpleSubstitutionCipher : public Cipher {
public:
    std::string encrypt(std::string &plaintext) override {
        std::string ciphertext = std::string(plaintext.length(), '0');

        for (uint64_t i = 0; i < plaintext.length(); i++) {
            uint64_t basePos = getCharacterPositon(plaintext.at(i));
            ciphertext[i] = this->key.substitution_key.value()[basePos];
        }

        return ciphertext;
    }

    std::string decrypt(std::string &ciphertext) override {
        std::string plaintext = std::string(ciphertext.length(), '0');

        for (uint64_t i = 0; i < ciphertext.length(); i++) {
            uint64_t cipherPos = this->getCharacterPositon(ciphertext.at(i));
            plaintext[i] = CHARACTER_MAP[cipherPos];
        }

        return plaintext;
    }

    void parseKey(std::string &key) override {
        std::string keyMap = std::string(CHARACTER_MAP_LENGTH, '0');
        uint64_t start = key.find("->\"") + sizeof("->\"");
        std::string substring = key.substr(start, key.length() - start - 1 /* Exclude the trailing quotation mark*/);

        if (substring.length() != CHARACTER_MAP_LENGTH) {
            emitMessage(FATAL, std::format("SimpleSubstitutionCipher::parseKey(): Invalid key length {}",
                                           key.length()));
            exit(EXIT_CODES::KEY_INVALID);
        }

        for (uint64_t i = 0; i < CHARACTER_MAP_LENGTH; i++) {
            if (!substring.contains(CHARACTER_MAP[i])) {
                emitMessage(FATAL, std::format("SimpleSubstitutionCipher::parseKey(): Invalid character {}",
                                               CHARACTER_MAP[i]));
                exit(EXIT_CODES::KEY_INVALID);
            }
        }
    }

private:
    uint64_t getCharacterPositon(char character) {
        if (!this->key.substitution_key.has_value()) {
            emitMessage(FATAL, "SimpleSubstitutionCipher::getCharacterPosition(): key must not be empty!");
            exit(EXIT_CODES::KEY_INVALID);
        }

        for (uint64_t i = 0; i < CHARACTER_MAP_LENGTH; i++) {
            if (character == this->key.substitution_key.value()[i]) {
                return i;
            }
        }

        emitMessage(FATAL, std::format(
                        "SimpleSubstitutionCipher::getCharacterPosition(): An invalid character was discovered :{}",
                        character));
        exit(EXIT_CODES::INVALID_CHARACTERS_FOUND);
    }
};
#endif //CODETALK_SIMPLESUBSITUTION_H
