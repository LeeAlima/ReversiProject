//
// Created by lee on 21/12/17.
//

#ifndef REVERSISERVER_CLOSECOMMAND_H
#define REVERSISERVER_CLOSECOMMAND_H
#include "../include/Command.h"

class CloseCommand: public Command {
public:
    virtual void execute(vector<string> args) {
        return;
    }
};
#endif //REVERSISERVER_CLOSECOMMAND_H
