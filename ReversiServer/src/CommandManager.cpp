
#include "../include/CommandManager.h"

CommandManager::CommandManager(RunServer *run_server){
    // for each key (start,list,join an close) sets (by creating) the
    // matches object as the value in the map
    commands_map["start"] = new StartCommand(run_server);
    commands_map["list"] = new ListCommand(run_server);
    commands_map["close"] = new CloseCommand(run_server);
    commands_map["join"] = new JoinCommand(run_server);
}

CommandManager::~CommandManager() {
    // delete all of the values in the map
    map<string, Command *>::iterator it;
    for (it = commands_map.begin(); it != commands_map.end(); it++) {
        delete it->second;
    }
}

void CommandManager::executeCommand(string command, vector<string> args) {
    // save in commandObj the right object (by using the map)
    Command *command_obj = commands_map[command];
    // call execute
    command_obj->execute(args);
}