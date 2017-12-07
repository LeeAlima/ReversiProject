//
// Created by lee on 06/12/17.
//

#ifndef REVERSI_REMOTEPLAYER_H
#define REVERSI_REMOTEPLAYER_H


#include "Player.h"
#include "Client.h"

class RemotePlayer : public Player{
public:

    RemotePlayer(char type,ConsoleScreen *screen,Client &client);

    string chooseCell(GameLogic &gameLogic) ;


protected:
    Client client;

};


#endif //REVERSI_REMOTEPLAYER_H
