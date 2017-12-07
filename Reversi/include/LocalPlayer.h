//
// Created by lee on 06/12/17.
//

#ifndef REVERSI_LOCALPLAYER_H
#define REVERSI_LOCALPLAYER_H


#include "Player.h"
#include "Client.h"

class LocalPlayer: public Player {

public:
    LocalPlayer(char type,ConsoleScreen *screen,Client &client);

    string chooseCell(GameLogic &gameLogic) ;

private:
    Client client;
    string fixPointToCom(string user_choice) const;
};


#endif //REVERSI_LOCALPLAYER_H
