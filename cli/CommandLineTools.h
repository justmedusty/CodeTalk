//
// Created by dustyn on 11/27/26.
//

#ifndef CODETALK_HELP_H
#define CODETALK_HELP_H
#include <string>


enum MessageLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    FATAL
};


void emitMessage(MessageLevel level, const std::string &message);

void printHelp();


#endif //CODETALK_HELP_H
