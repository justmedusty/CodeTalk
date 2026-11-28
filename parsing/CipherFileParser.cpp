//
// Created by dustyn on 11/27/26.
//

#include "CipherFileParser.h"
#include <format>
#include <fstream>

std::vector<uint8_t> parseColumnarTranspositionKey(std::string line) {
}

uint64_t Parser::getNumEntries() {
    std::ifstream entryFile(this->cipherFile);
    if (!entryFile.is_open()) {
        emitMessage(FATAL, std::format("getNumEntries: Could not open file {}", this->cipherFile));
        exit(EXIT_CODES::FILE_NOT_FOUND);
    }
    std::string line;
    uint64_t cipherStartCount = 0;
    uint64_t cipherEndCount = 0;
    while (std::getline(entryFile, line)) {
        if (line == "CIPHER_START") {
            cipherStartCount++;
        }

        if (line == "CIPHER_END") {
            cipherEndCount++;
        }
    }

    if (cipherStartCount != cipherEndCount) {
        emitMessage(
            FATAL, "getNumEntries: Not all CIPHER_START/CIPHER_END tags are valid, some are unopened or unclosed");
        exit(EXIT_CODES::CIPHER_INVALID);
    }

    //Cipher tags are only used by multi cipher cipher files, so if there are none the number of ciphers is one
    uint64_t cipherCount = cipherStartCount == 0 ? 1 : cipherStartCount;

    if (cipherCount > 1) {
        this->stacked_ciphers = true;
    }

    return cipherCount;
}

std::unique_ptr<Cipher> Parser::parseEntry(uint64_t cipherNum) {
    std::ifstream entryFile(this->cipherFile);

    if (!entryFile.is_open()) {
        emitMessage(FATAL, std::format("parseEntry: Could not open file {}", this->cipherFile));
        exit(EXIT_CODES::FILE_NOT_FOUND);
    }

    std::string line;
    bool in_cipher = false;
    bool in_cipher_definition = false;
    bool in_key = false;
    bool in_cipher_extras = false;
    uint64_t cipherCount = 0;


    while (std::getline(entryFile, line)) {

        //Handle comments
        if (line.starts_with('#')) {
            continue;
        }

        if (this->stacked_ciphers) {

            if (line.starts_with(MULTI_START_STRING)) {
                in_cipher = true;
                continue;
            }

            if (line.starts_with(MULTI_END_STRING)) {
                in_cipher = false;
                cipherCount++;
                continue;
            }

        }
    }
}

void Parser::parse() {
    if (!std::filesystem::exists(this->cipherFile)) {
        emitMessage(FATAL, std::format("The file being passed {} does not exist", this->cipherFile));
        exit(EXIT_CODES::FILE_NOT_FOUND);
    }

    uint64_t numCiphers = getNumEntries();

    for (uint64_t i = 0; i < numCiphers; i++) {

    }
}
