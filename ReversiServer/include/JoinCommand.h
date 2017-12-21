//
// Created by lee on 21/12/17.
//

#ifndef REVERSISERVER_JOINCOMMAND_H
#define REVERSISERVER_JOINCOMMAND_H

#include "../include/Command.h"

class JoinCommand: public Command {
public:
    virtual void execute(vector<string> args) {
        return;
    }
};
#endif //REVERSISERVER_JOINCOMMAND_H
