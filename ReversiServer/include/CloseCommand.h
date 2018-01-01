
#ifndef REVERSISERVER_CLOSECOMMAND_H
#define REVERSISERVER_CLOSECOMMAND_H

#include "../include/Command.h"
#include "RunServer.h"

class CloseCommand : public Command {
public:
    /**
     * If the client send the server close XXX than this class execute method
     * is called.
     * @param run - as a RunServer object
     */
    CloseCommand();

    /*
     * destructor
     */
    virtual ~CloseCommand();

    /**
     * In this method I called closeGame in RunServer
     * @param args - the arguments from the client
     */
    virtual void execute(vector<string> args,int clientSocket);

private:
    string ok_close_;
    string not_ok_close_;
};

#endif //REVERSISERVER_CLOSECOMMAND_H