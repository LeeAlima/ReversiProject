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
    vector<Game*> *getVecOfGames();

private:
    vector<Game*> *list_of_games;
};


#endif //REVERSISERVER_SERVERCONTAINER_H
