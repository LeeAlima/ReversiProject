
#ifndef REVERSISERVER_LISTCOMMAND_H
#define REVERSISERVER_LISTCOMMAND_H

#include "Command.h"
#include "RunServer.h"

class ListCommand : public Command {
public:
    /**
     * constructor of ListCommand
     * @param run - RunServer obj
     */
    ListCommand();

    /**
     * destructor
     */
    virtual ~ListCommand();

    /**
   * In this method I called listOfGames in RunServer
   * @param args - the arguments from the client
   */
    virtual void execute(vector<string> args,int clientSocket);

private:
    string not_ok_list_;
};

#endif //REVERSISERVER_LISTCOMMAND_H