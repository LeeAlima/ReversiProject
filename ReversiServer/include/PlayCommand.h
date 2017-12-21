//
// Created by lee on 21/12/17.
//

#ifndef REVERSISERVER_PLAYCOMMAND_H
#define REVERSISERVER_PLAYCOMMAND_H
#include "../include/Command.h"

class PlayCommand: public Command {
public:
    virtual void execute(vector<string> args) {
        return;
    }
};
#endif //REVERSISERVER_PLAYCOMMAND_H
