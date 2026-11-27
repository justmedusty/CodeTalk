//
// Created by dustyn on 11/27/26.
//

#ifndef CODETALK_CIPHEREXTRAS_H
#define CODETALK_CIPHEREXTRAS_H
#include "Cipher.h"

void applyNullCipher(CipherExtras cipherType, std::string &text);

void removeNullCipher(CipherExtras cipherType, std::string &text);

void applyTransposition(CipherExtras cipherType, std::string &text,
                        std::optional<std::vector<uint8_t> &> transposition_key);

void removeTransposition(CipherExtras cipherType, std::string &text,
                         std::optional<std::vector<uint8_t> &> transposition_key);
#endif //CODETALK_CIPHEREXTRAS_H
