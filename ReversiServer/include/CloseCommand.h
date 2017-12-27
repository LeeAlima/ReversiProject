//
// Created by lee on 21/12/17.
//

#ifndef REVERSISERVER_CLOSECOMMAND_H
#define REVERSISERVER_CLOSECOMMAND_H
#include "../include/Command.h"
#include "RunServer.h"

class CloseCommand: public Command {
public:
    CloseCommand(RunServer *_run);

    virtual ~CloseCommand();

    virtual void execute(vector<string> args);
private:
    RunServer *_run;
};
#endif //REVERSISERVER_CLOSECOMMAND_H
