//
// Created by dustyn on 11/27/26.
//

#ifndef CODETALK_CIPHEREXTRAS_H
#define CODETALK_CIPHEREXTRAS_H
#include "Cipher.h"

void applyNullCipher(CipherExtras cipherType, std::string& text);

void removeNullCipher(CipherExtras cipherType, std::string& text);
#endif //CODETALK_CIPHEREXTRAS_H
