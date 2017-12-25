//
// Created by omer on 25/12/17.
//

#ifndef REVERSISERVER_GAMEROOM_H
#define REVERSISERVER_GAMEROOM_H


#include "Game.h"
#include <pthread.h>

class GameRoom {

public:
    GameRoom(Game *game);

    /**
    * this method handle the client by trying to read from the socket
    * and end game if needed
    * @param sender - number of sender
    * @param receiver - number of receiver
    * @return false if there was a problem of disconnection) and true
    * if the game can continue
    */
    bool handleMove(int sender, int receiver);

    void addThread();

    static void* runGame(void* obj);

private:
    Game *game;
};


#endif //REVERSISERVER_GAMEROOM_H
