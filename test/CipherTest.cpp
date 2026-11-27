//
// Created by dustyn on 11/27/26.
//
#define BOOST_TEST_MODULE CipherTest

#include <boost/test/unit_test.hpp>

#include "../ciphers/Caesar.h"
#include "../ciphers/Cipher.h"

BOOST_AUTO_TEST_CASE(test_caesar_cipher) {
    std::string test_string = "Hello";

    CaesarCipher cipher {
        "/tmp/testcipher1"
    };

}