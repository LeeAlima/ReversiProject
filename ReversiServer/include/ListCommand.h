//
// Created by lee on 21/12/17.
//

#ifndef REVERSISERVER_LISTCOMMAND_H
#define REVERSISERVER_LISTCOMMAND_H

#include "Command.h"

class ListCommand: public Command {
public:
    virtual void execute(vector<string> args) {
        return;
    }
};

#endif //REVERSISERVER_LISTCOMMAND_H
