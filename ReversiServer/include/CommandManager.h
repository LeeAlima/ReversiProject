
#ifndef REVERSISERVER_COMMANDMANAGER_H
#define REVERSISERVER_COMMANDMANAGER_H

#include <map>
#include "../include/Command.h"
#include "RunServer.h"
#include "../include/StartCommand.h"
#include "../include/ListCommand.h"
#include "../include/CloseCommand.h"
#include "../include/JoinCommand.h"

/**
 * The class handle the commands sent from the user and
 * execute the right command calling the right command class.
 */
class CommandManager {
public:

    static CommandManager* getInstance();
    /**
     * This method call the execute method of the right command
     * using the map member
     * @param command - the command that should be execute
     * @param args - the args for the command
     */
    void executeCommand(string command, vector<string> args,int clientSocket);

private:
    /**
   * constructor for RunServer
   * @param run_server - as RunServer object (contain the method of
   * opening, closing , printing and joining a game)
   */
    CommandManager();

    /**
     * destructor
     */
    ~CommandManager();
    static CommandManager* instance;
    static pthread_mutex_t lock;
    /*
     * a map that matches a string to a command object
     */
    map<string, Command *> commands_map;
};

#endif //REVERSISERVER_COMMANDMANAGER_H