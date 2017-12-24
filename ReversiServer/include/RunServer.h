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
    RunServer(int clientSocket);

    virtual ~RunServer();
    void sendMessageToClient(string msg);
    void startNewGame(vector<string> args);
    void listOfGames(vector<string> args);
    void joinToGame(vector<string> args);
    void closeGame(vector<string> args);
    void playGame(vector<string> args);

private:
    list<Game> list_of_games;
    int clientSocket;
};


#endif //REVERSISERVER_RUNSERVER_H
