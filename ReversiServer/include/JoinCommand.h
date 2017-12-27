//
// Created by lee on 21/12/17.
//

#ifndef REVERSISERVER_JOINCOMMAND_H
#define REVERSISERVER_JOINCOMMAND_H

#include "../include/Command.h"
#include "RunServer.h"

class JoinCommand: public Command {
public:
    JoinCommand(RunServer *_run);

    virtual ~JoinCommand();

    virtual void execute(vector<string> args) ;
private:
    RunServer *_run;
};
#endif //REVERSISERVER_JOINCOMMAND_H
