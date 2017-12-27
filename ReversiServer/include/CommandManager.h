//
// Created by lee on 21/12/17.
//

#ifndef REVERSISERVER_COMMANDMANAGER_H
#define REVERSISERVER_COMMANDMANAGER_H

#include <map>
#include "../include/Command.h"
#include "RunServer.h"

class CommandManager {
public:
    CommandManager(RunServer *run_server);
    ~CommandManager();
    void executeCommand(string command,
                        vector<string> args);
private:
    map<string, Command *> commandsMap;
};

#endif //REVERSISERVER_COMMANDMANAGER_H
