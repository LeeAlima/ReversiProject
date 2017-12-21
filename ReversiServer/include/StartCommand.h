//
// Created by lee on 21/12/17.
//

#ifndef REVERSISERVER_STARTCOMMAND_H
#define REVERSISERVER_STARTCOMMAND_H
#include "../include/Command.h"

class StartCommand: public Command {
public:
    virtual void execute(vector<string> args) {
        return;
    }
};
#endif //REVERSISERVER_STARTCOMMAND_H
