//
// Created by lee on 21/12/17.
//

#include "../include/CommandManager.h"
#include "../include/StartCommand.h"
#include "../include/ListCommand.h"
#include "../include/PlayCommand.h"
#include "../include/CloseCommand.h"
#include "../include/JoinCommand.h"
#include "../include/RunServer.h"

CommandManager::CommandManager(RunServer *run_server) {
    commandsMap["start"] = new StartCommand(run_server);
    commandsMap["list"] = new ListCommand(run_server);
    /*commandsMap["play"] = new PlayCommand(run_server);*/
    commandsMap["close"] = new CloseCommand(run_server);
    commandsMap["join"] = new JoinCommand(run_server);
}
void CommandManager::executeCommand(string
                                     command, vector<string> args) {
    Command *commandObj = commandsMap[command];
    commandObj->execute(args);
}
CommandManager::~CommandManager() {
    map<string, Command *>::iterator it;
    for (it = commandsMap.begin(); it !=
                                   commandsMap.end(); it++) {
        delete it->second;
    }
}