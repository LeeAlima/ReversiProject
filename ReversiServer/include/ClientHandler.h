//
// Created by omer on 25/12/17.
//

#ifndef REVERSISERVER_CLIENTHANDLER_H
#define REVERSISERVER_CLIENTHANDLER_H

#include <iostream>
#include "vector"
#include "CommandManager.h"

using namespace std;

class ClientHandler {
public:

    ClientHandler(int client_Socket);

    void setClient_Socket(int client_Socket);

    static void* handleCommand(void* obj);
    pair<string, vector<string>> extractCommand(string msg);


private:
    int client_Socket;
    RunServer *runServer;
    CommandManager *comMan;
    vector<Game *> *list_of_games;
};


#endif //REVERSISERVER_CLIENTHANDLER_H
