//
// Created by dustyn on 11/27/26.
//

#ifndef CODETALK_CIPHERFILEPARSER_H
#define CODETALK_CIPHERFILEPARSER_H
#include <filesystem>
#include "../ciphers/Cipher.h"

//String definitions used for parsing cipher files
#define CAESAR_STRING "CAESAR"
#define SIMPLE_SUBSTITUTION_STRING "SIMPLE_SUBSTITUTION"
#define ONE_TIME_PAD_STRING "ONE_TIME_PAD"

#define MULTI_START_STRING "CIPHER_START"
#define MULTI_END_STRING "CIPHER_END"

#define EVERY_OTHER_STRING "EVERY_OTHER"
#define EVERY_THIRD_STRING "EVERY_THIRD"
#define EVERY_FOURTH_STRING "EVERY_FOURTH"
#define EVERY_FIFTH_STRING "EVERY_FIFTH"
#define EVERY_SIXTH_STRING "EVERY_SIXTH"
#define EVERY_SEVENTH_STRING "EVERY_SEVENTH"

#define ZIGZAG_TRANSPOSITION_STRING "ZIGZAG_TRANSPOSITION"
#define REVERSE_TRANSPOSITION_STRING "REVERSE_TRANSPOSITION"
#define COLUMNAR_TRANSPOSITION_STRING "COLUMNAR_TRANSPOSITION"




class Parser {
public:

    explicit Parser(std::filesystem::path cipherFile) {
        this->stacked_ciphers = false; //assumes not stacked
        this->cipherFile = std::move(cipherFile);
    };
    bool stacked_ciphers;

    void parse();

private:

    uint64_t getNumEntries();
    std::unique_ptr<Cipher> parseEntry(uint64_t cipherNum);

    // Stacked ciphers are a possibility so it should include a list/ vector
    std::vector<std::unique_ptr<Cipher> > ciphers;
    std::filesystem::path cipherFile;
};
#endif //CODETALK_CIPHERFILEPARSER_H
