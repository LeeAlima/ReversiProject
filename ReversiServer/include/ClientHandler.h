//
// Created by omer on 25/12/17.
//

#ifndef REVERSISERVER_CLIENTHANDLER_H
#define REVERSISERVER_CLIENTHANDLER_H

#include <iostream>
#include "vector"
#include "CommandManager.h"
#include "ServerContainer.h"

using namespace std;

class ClientHandler {
public:

    ClientHandler(int client_Socket,ServerContainer *serverContainer);
    static void* handleCommand(void* obj);
    pair<string, vector<string>> extractCommand(string msg);


private:
    int client_Socket;
    RunServer *runServer;
    CommandManager *comMan;
    ServerContainer *serverContainer;
};


#endif //REVERSISERVER_CLIENTHANDLER_H
