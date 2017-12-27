//
// Created by lee on 21/12/17.
//

#ifndef REVERSISERVER_STARTCOMMAND_H
#define REVERSISERVER_STARTCOMMAND_H
#include "../include/Command.h"
#include "RunServer.h"

class StartCommand: public Command {
public:
    StartCommand(RunServer *_run);

    virtual ~StartCommand();

    virtual void execute(vector<string> args) ;
private:
    RunServer *_run;
};
#endif //REVERSISERVER_STARTCOMMAND_H
