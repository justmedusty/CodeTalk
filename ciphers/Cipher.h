//
// Created by dustyn on 11/27/26.
//

#ifndef CODETALK_CIPHER_H
#define CODETALK_CIPHER_H
#include <cstring>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>


#include "../CodeTalk.h"
#include "../cli/CommandLineTools.h"
#include "CipherKey.h"

//Shared by all ciphers, this could be modified to include other languages if someone wanted
//no spaces or symbols because it must remain easily speakable. spaces and symbols will be removed during encryption
inline std::string CHARACTER_MAP = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
inline auto CHARACTER_MAP_LENGTH = CHARACTER_MAP.length();


class Cipher {
public:


    virtual ~Cipher() = default;
    virtual std::string encrypt(std::string plaintext) = 0;
    virtual std::string decrypt(std::string ciphertext) = 0;

    Cipher(const std::string &pathToCipherFile) : key() {
        if (!std::filesystem::exists(pathToCipherFile)) {
            std::cerr << "FATAL: The path to the cipher file (" << pathToCipherFile << ") does not exist." << std::endl;
            exit(EXIT_CODES::FILE_NOT_FOUND);
        }

        this->cipherFile = pathToCipherFile;
    }

    static int32_t getCharacterPosition(const char *character) {
        if (!CHARACTER_MAP.contains(character)) {
            return RETURN_CODES::NOT_FOUND;
        }

        //this is not efficient but it does not need to be. can circle back to it later if needed. The speed that this needs to operate on
        // is human level, not machine level speeds

        for (int32_t i = 0; i < CHARACTER_MAP_LENGTH; i++) {
            if (CHARACTER_MAP[i] == *character) {
                return i;
            }
        }


        emitMessage(MessageLevel::FATAL,"getCharacterPosition() reached the end without returning a value");
        exit(RETURN_CODES::NOT_FOUND);
    }

    [[nodiscard]] CipherType getCipherType() const {
        return this->type;
    }

protected:
    CipherKey key;
    CipherType type = CipherType::UNKNOWN;
    std::vector<char> inBuffer;
    std::vector<char> outBuffer;
    std::filesystem::path cipherFile;
};
#endif //CODETALK_CIPHER_H
