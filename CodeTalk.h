//
// Created by dustyn on 11/27/26.
//

#ifndef CODETALK_CODETALK_H
#define CODETALK_CODETALK_H

//Program centric definitions

enum CipherType {
    UNKNOWN,
    CAESAR,
    CUSTOM_EXPRESSION,
    ONE_TIME_PAD,
    SIMPLE_SUBSTITUTION,
    POLYBIUS_SQUARE,
    PLAYFAIR
};

//Throws random junk in and the only meaningful letter is every Xth character, this is not its own cipher but used in conjunction with another cipher
enum CipherExtras {
    NONE,
    EVERY_OTHER,
    EVERY_THIRD,
    EVERY_FOURTH,
    EVERY_FIFTH,
    EVERY_SIXTH,
    EVERY_SEVENTH,
};

enum EXIT_CODES {
    OK = 0,
    FILE_NOT_FOUND,
    CIPHER_INVALID,
    EXPRESSION_INVALID,
    KEY_INVALID,
    // add more as needed
};

enum RETURN_CODES {
    NOT_FOUND = -1
    //add more as needed
};
#endif //CODETALK_CODETALK_H
