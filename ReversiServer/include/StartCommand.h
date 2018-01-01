
#ifndef REVERSISERVER_STARTCOMMAND_H
#define REVERSISERVER_STARTCOMMAND_H

#include "../include/Command.h"
#include "RunServer.h"

class StartCommand : public Command {
public:
    /**
     * constructor for startCommand
     * @param run - RunServer obj
     */
    StartCommand();

    /**
     * destructor
     */
    virtual ~StartCommand();

    /**
   * In this method I called startNewGame in RunServer
   * @param args - the arguments from the client
   */
    virtual void execute(vector<string> args,int clientSocket);

private:
    RunServer *run;
    string ok_start_;
    string not_ok_start_;
};

#endif //REVERSISERVER_STARTCOMMAND_H
