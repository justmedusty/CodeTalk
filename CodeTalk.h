//
// Created by dustyn on 11/27/26.
//

#ifndef CODETALK_CODETALK_H
#define CODETALK_CODETALK_H

//Program centric definitions
#define DEFAULT_COLUMN_WIDTH 7

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
    REVERSE_TRANSPOSITION,// (7,6,5,4,3,2,1)
    ZIGZAG_TRANSPOSITION, // (2,5,1,6,3,7,4)
    COLUMNAR_TRANSPOSITION //requires key in cipher file, can be of any length the others are stuck at DEFAULT_COLUMN_WIDTH
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
