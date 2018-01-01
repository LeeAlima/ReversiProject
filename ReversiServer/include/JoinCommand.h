
#ifndef REVERSISERVER_JOINCOMMAND_H
#define REVERSISERVER_JOINCOMMAND_H

#include "../include/Command.h"
#include "RunServer.h"

class JoinCommand : public Command {
public:
    /**
     * the constructor of JoinCommand
     * @param run - RunServer obj
     */
    JoinCommand();

    /**
     * destructor
     */
    virtual ~JoinCommand();

    /**
    * In this method I called joinToGame in RunServer
    * @param args - the arguments from the client
    */
    virtual void execute(vector<string> args,int clientSocket);

private:
    RunServer *run;
    string ok_join_;
    string not_such_game_join_;
    string game_is_playing_;
};

#endif //REVERSISERVER_JOINCOMMAND_H