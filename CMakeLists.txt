cmake_minimum_required(VERSION 4.3)
project(CodeTalk)

set(CMAKE_CXX_STANDARD 26)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)


add_library(CodeTalkCore
        ciphers/Cipher.h
        cli/CommandLineTools.cpp
        cli/CommandLineTools.h
        CodeTalk.h
        ciphers/CipherKey.h
        parsing/CipherFileParser.cpp
        parsing/CipherFileParser.h
        ciphers/Caesar.h
        ciphers/CipherExtras.cpp
        ciphers/CipherExtras.h
        test/CipherTest.cpp
)

add_executable(CodeTalk main.cpp
)

add_executable(CodeTalkCipherTest
        test/CipherTest.cpp)

target_link_libraries(CodeTalkCipherTest PRIVATE
        CodeTalkCore
        Boost::unit_test_framework)

target_link_libraries(CodeTalk PRIVATE CodeTalkCore)