#ifndef REVERSISERVER_CLIENTHANDLER_H
#define REVERSISERVER_CLIENTHANDLER_H

#include <iostream>
#include "vector"
#include "CommandManager.h"
#include "ServerContainer.h"

#define MaxSize 20

using namespace std;

class ClientHandler {
public:
    /**
     * constructor for ClientHandler
     * @param client_Socket - the number of the client socket
     * @param serverContainer - a pointer to the server container
     */
    ClientHandler(int client_Socket,ServerContainer *serverContainer);

    /**
     * destructor
     */
    ~ClientHandler();

    /**
     * static method that handle the client's commands ( is being called
     * in threads to handle many clients at the same time)
     * @param obj - as void * but will cast to ClientHandler object
     * in the method
     * @return void * - false for an error
     */
    static void* handleCommand(void* obj);

private:
    int client_Socket_;
    RunServer *run_server_;
    CommandManager *command_mannager_;
    ServerContainer *server_container_;

    /**
     * this method is called from handleCommand and by the data received
     * from the client - the method splits it by space and return a pair
     * @param msg - the message from client
     * @return pair with the data splitted
     */
    pair<string, vector<string>> extractCommand(string msg);
};

#endif //REVERSISERVER_CLIENTHANDLER_H