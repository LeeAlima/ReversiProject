//
// Created by lee on 24/12/17.
//

#ifndef REVERSISERVER_RUNSERVER_H
#define REVERSISERVER_RUNSERVER_H

#include <iostream>
#include <vector>
#include <list>
#include "Game.h"

using namespace std;



class RunServer {
public:
    RunServer(int clientSocket,vector<Game*> *list);

    virtual ~RunServer();

    void setClientSocket(int clientSocket);

    void sendMessageToClient(string msg);
    void startNewGame(vector<string> args);
    void listOfGames(vector<string> args);
    void joinToGame(vector<string> args);
    void closeGame(vector<string> args);

private:
    vector<Game *> *list_of_games;
    int clientSocket;

    string notOkStart;
    string okStart;
    string okJoin;
    string notSuchGameJoin;
    string gameIsPlaying;
    string okClose;
    string notOkClose;
    string notOkList;
};


#endif //REVERSISERVER_RUNSERVER_H
