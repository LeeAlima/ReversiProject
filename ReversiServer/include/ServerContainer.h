//
// Created by omer on 28/12/17.
//

#ifndef REVERSISERVER_SERVERCONTAINER_H
#define REVERSISERVER_SERVERCONTAINER_H


#include <vector>
#include "Game.h"

class ServerContainer {
public:
    ServerContainer();
    ~ServerContainer();
    void addGame(Game *game);
    bool removeGame(string name);
    bool removeClientSocket(int client_socket);

    vector<int> getClient_sockets() const;

    void addClientSocket(int client_socket);
    vector<Game*> *getVecOfGames();

private:
    vector<Game*> *list_of_games;
    vector<int> client_sockets;


};


#endif //REVERSISERVER_SERVERCONTAINER_H
