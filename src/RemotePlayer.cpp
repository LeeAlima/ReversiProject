//
// Created by lee on 06/12/17.
//

#include "../include/RemotePlayer.h"

RemotePlayer::RemotePlayer(char type, ConsoleScreen *screen, Client &client) :
        Player(type,screen), client(client){

}


string RemotePlayer::chooseCell(GameLogic &gameLogic) {
    char* move = this->client.receive();
    return (string)move;
}