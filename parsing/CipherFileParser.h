//
// Created by dustyn on 11/27/26.
//

#ifndef CODETALK_CIPHERFILEPARSER_H
#define CODETALK_CIPHERFILEPARSER_H
#include <filesystem>
#include "../ciphers/Cipher.h"

class Parser {
public:
    bool stacked_ciphers;


private:
    std::vector<Cipher> ciphers; // Stacked ciphers are a possibility so it should include a list/ vector
    std::filesystem::path cipherFile;


};
#endif //CODETALK_CIPHERFILEPARSER_H
