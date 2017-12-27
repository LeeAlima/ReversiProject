//
// Created by lee on 21/12/17.
//

#ifndef REVERSISERVER_LISTCOMMAND_H
#define REVERSISERVER_LISTCOMMAND_H

#include "Command.h"
#include "RunServer.h"

class ListCommand: public Command {
public:
    ListCommand(RunServer *_run);

    virtual ~ListCommand() ;

public:
    virtual void execute(vector<string> args);

private:
    RunServer *_run;
};

#endif //REVERSISERVER_LISTCOMMAND_H
