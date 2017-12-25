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

    bool handleCommand(int clientSocket);
    pair<string, vector<string>> extractCommand(string msg);
    static void* executeHandleCommand(void *tArgs) ;

    void handle(int client_Socket);

private:
    CommandManager *comMan;
};


#endif //REVERSISERVER_CLIENTHANDLER_H
