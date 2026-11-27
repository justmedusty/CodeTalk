//
// Created by dustyn on 11/27/26.
//

#ifndef CODETALK_CIPHERKEY_H
#define CODETALK_CIPHERKEY_H
#pragma once
#include <vector>

#include "../CodeTalk.h"

class CipherKey {
public:
     CipherType cipherType;
     std::vector<uint8_t> key;
     CipherExtras extras = NONE; // default is none

private:
};
#endif //CODETALK_CIPHERKEY_H
