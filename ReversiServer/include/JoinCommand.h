
#ifndef REVERSISERVER_JOINCOMMAND_H
#define REVERSISERVER_JOINCOMMAND_H

#include "../include/Command.h"
#include "RunServer.h"

class JoinCommand: public Command {
public:
    /**
     * the constructor of JoinCommand
     * @param _run - RunServer obj
     */
    JoinCommand(RunServer *_run);

    /**
     * destructor
     */
    virtual ~JoinCommand();

    /**
    * In this method I called joinToGame in RunServer
    * @param args - the arguments from the client
    */
    virtual void execute(vector<string> args);

private:
    RunServer *run;
};
#endif //REVERSISERVER_JOINCOMMAND_H