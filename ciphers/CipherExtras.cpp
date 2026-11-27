//
// Created by dustyn on 11/27/26.
//

#include "CipherExtras.h"

#include <string>

#include "../CodeTalk.h"

void applyNullCipher(CipherExtras cipherType, std::string &text) {
    uint64_t nullFactor = 0;

    switch (cipherType) {
        case CipherExtras::EVERY_OTHER: nullFactor = 2;
            break;
        case CipherExtras::EVERY_THIRD: nullFactor = 3;
            break;
        case CipherExtras::EVERY_FOURTH: nullFactor = 4;
            break;
        case CipherExtras::EVERY_FIFTH: nullFactor = 5;
            break;
        case CipherExtras::EVERY_SIXTH: nullFactor = 6;
            break;
        case CipherExtras::EVERY_SEVENTH: nullFactor = 7;
            break;
        default: {
            emitMessage(FATAL, "applyNullCipher: called with non null cipher option");
            exit(EXIT_CODES::CIPHER_INVALID);
        }
    }

    uint64_t extra = text.length() % nullFactor != 0 ? nullFactor - (text.length() % nullFactor) : 0;

    auto padded = std::string((text.length() * nullFactor) + extra, 0);

    for (int i = 0; i < padded.size(); i++) {
        if (i % nullFactor == 0) {
            continue;
        }

        padded[i] = CHARACTER_MAP[std::rand() % CHARACTER_MAP_LENGTH];
    }

    for (int i = 0; i < text.length(); i++) {
        padded[i * nullFactor] = text[i];
    }

    text = std::move(padded);
}

void removeNullCipher(CipherExtras cipherType, std::string &text) {
    uint64_t nullFactor = 0;

    switch (cipherType) {
        case CipherExtras::EVERY_OTHER: nullFactor = 2;
            break;
        case CipherExtras::EVERY_THIRD: nullFactor = 3;
            break;
        case CipherExtras::EVERY_FOURTH: nullFactor = 4;
            break;
        case CipherExtras::EVERY_FIFTH: nullFactor = 5;
            break;
        case CipherExtras::EVERY_SIXTH: nullFactor = 6;
            break;
        case CipherExtras::EVERY_SEVENTH: nullFactor = 7;
            break;
        default: {
            emitMessage(FATAL, "removeNullCipher: called with non null cipher option");
            exit(EXIT_CODES::CIPHER_INVALID);
        }
    }

    std::string decoded_text = std::string(text.length() / nullFactor, 0);
    uint64_t counter = 0;
    for (int i = nullFactor; i < text.length(); i += nullFactor) {
        decoded_text[counter++] = text[i];
    }

    text = std::move(decoded_text);
}
