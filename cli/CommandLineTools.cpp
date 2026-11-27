//
// Created by dustyn on 11/27/26.
//

#include "CommandLineTools.h"

#include <iostream>
#include <ostream>

MessageLevel applicationLogLevel = MessageLevel::ERROR;

void printHelp() {
    std::cout <<
            "This tool is for analog radio modes (FM, SSB, CW, etc) and provides a means for secure communications in a mode where digital encryption is not available."
            << std::endl;
    std::cout <<
            "It will read a specification file from your home directory which will contain a cipher, a key, and any other information needed by the cipher in use."
            << std::endl;
    std::cout <<
            "Communication will take place by voice or morse code, so there are helper functions to convert your encrypted message to phonetic alphabet for easier transmission."
            << std::endl;
    //TODO finish this
}

static std::string level2string(MessageLevel level) {
    switch (level) {
        case MessageLevel::DEBUG: return "DEBUG";
        case MessageLevel::INFO: return "INFO";
        case MessageLevel::ERROR: return "ERROR";
        case MessageLevel::WARNING: return "WARNING";
        default: return "UNKNOWN";
    }
}

void emitMessage(MessageLevel level, const std::string& message) {

    if (level < applicationLogLevel) {
        return;
    }

    std::cout << level2string(level) << ": " << message << std::endl;
}
