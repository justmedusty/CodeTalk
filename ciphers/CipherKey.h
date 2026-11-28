//
// Created by dustyn on 11/27/26.
//

#ifndef CODETALK_CIPHERKEY_H
#define CODETALK_CIPHERKEY_H
#pragma once
#include <vector>

#include "../CodeTalk.h"

/*
 * This should probably be an abstract class but for now this will stay
 */
class CipherKey {
public:
    CipherKey();

    ~CipherKey() = default;

    CipherType cipherType;
    std::optional<std::vector<uint8_t>> key_material;
    std::optional<std::string>  substitution_key;
    CipherExtras extras = NONE; // default is none
    std::optional<std::vector<uint8_t>> transposition_order; // only if using columnar transposition
private:
};
#endif //CODETALK_CIPHERKEY_H
