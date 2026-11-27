cmake_minimum_required(VERSION 4.3)
project(CodeTalk)

set(CMAKE_CXX_STANDARD 26)

add_executable(CodeTalk main.cpp
        ciphers/Cipher.h
        cli/CommandLineTools.cpp
        cli/CommandLineTools.h
        CodeTalk.h)
