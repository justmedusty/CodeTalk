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

    auto padded = std::string((text.length() * nullFactor) + extra, '0');

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

    auto decoded_text = std::string(text.length() / nullFactor, '0');
    uint64_t counter = 0;
    for (uint64_t i = nullFactor; i < text.length(); i += nullFactor) {
        decoded_text[counter++] = text[i];
    }

    text = std::move(decoded_text);
}

void applyTransposition(CipherExtras cipherType, std::string &text,
                        std::optional<std::vector<uint8_t> &> transposition_key) {
    bool need_key = cipherType == CipherExtras::COLUMNAR_TRANSPOSITION;

    if (need_key && !transposition_key.has_value()) {

        emitMessage(FATAL, "applyTransposition: called with columnar transposition option with no provided key!");
        exit(EXIT_CODES::CIPHER_INVALID);

    }

    uint64_t column_width = CipherExtras::COLUMNAR_TRANSPOSITION
                                ? transposition_key.value().size()
                                : DEFAULT_COLUMN_WIDTH;

    uint64_t padding_needed = text.length() % column_width != 0 ? column_width - (text.length() % column_width) : 0;

    auto transposed_text = std::string(text.length() + padding_needed, '0');

    for (uint64_t i = 0; i < text.length(); i += column_width) {

        if (cipherType == CipherExtras::COLUMNAR_TRANSPOSITION) {

            for (uint64_t j = 0; j < column_width; j++) {

                transposed_text[i + j] = text[i + transposition_key.value()[j]];
            }

        } else if (cipherType == CipherExtras::REVERSE_TRANSPOSITION) {

            for (uint64_t j = 0; j < column_width; j++) {

                transposed_text[i + j] = text[i + (DEFAULT_COLUMN_WIDTH - j)];

            }

        } else if (cipherType == CipherExtras::ZIGZAG_TRANSPOSITION) {
#if DEFAULT_COLUMN_WIDTH != 7
#error This needs to be changed when the default column width changes
#endif
            transposed_text[i] = text[i + 1];
            transposed_text[i + 1] = text[i + 4];
            transposed_text[i + 2] = text[i + 0];
            transposed_text[i + 3] = text[i + 5];
            transposed_text[i + 4] = text[i + 2];
            transposed_text[i + 5] = text[i + 6];
            transposed_text[i + 6] = text[i + 3];
        } else {

            emitMessage(FATAL, "applyTransposition: This branch was never supposed to be taken!");
            exit(EXIT_CODES::CIPHER_INVALID);

        }
    }
}

void undoTransposition(CipherExtras cipherType, std::string &text,
                       std::optional<std::vector<uint8_t> &> transposition_key) {
    bool need_key = cipherType == CipherExtras::COLUMNAR_TRANSPOSITION;

    if (need_key && !transposition_key.has_value()) {
        emitMessage(FATAL, "undoTransposition: called with columnar transposition option with no provided key!");
        exit(EXIT_CODES::CIPHER_INVALID);
    }

    uint64_t column_width = CipherExtras::COLUMNAR_TRANSPOSITION
                                ? transposition_key.value().size()
                                : DEFAULT_COLUMN_WIDTH;

    auto untransposed_text = std::string(text.length(), '0');

    for (uint64_t i = 0; i < text.length(); i += column_width) {

        if (cipherType == CipherExtras::COLUMNAR_TRANSPOSITION) {

            for (uint64_t j = 0; j < column_width; j++) {

                untransposed_text[i + transposition_key.value()[j]] = text[i + j];
            }

        } else if (cipherType == CipherExtras::REVERSE_TRANSPOSITION) {

            for (uint64_t j = 0; j < column_width; j++) {
                untransposed_text[i + (DEFAULT_COLUMN_WIDTH - j)] = text[i + j];
            }

        } else if (cipherType == CipherExtras::ZIGZAG_TRANSPOSITION) {
#if DEFAULT_COLUMN_WIDTH != 7
#error This needs to be changed when the default column width changes
#endif
            untransposed_text[i + 6] = text[i + 1];
            untransposed_text[i + 5] = text[i + 4];
            untransposed_text[i + 4] = text[i + 0];
            untransposed_text[i + 3] = text[i + 5];
            untransposed_text[i + 2] = text[i + 2];
            untransposed_text[i + 1] = text[i + 6];
            untransposed_text[i] = text[i + 3];
        } else {

            emitMessage(FATAL, "applyTransposition: This branch was never supposed to be taken!");
            exit(EXIT_CODES::CIPHER_INVALID);

        }
    }
}
