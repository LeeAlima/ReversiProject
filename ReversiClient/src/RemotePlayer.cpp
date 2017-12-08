
#include "../include/RemotePlayer.h"

RemotePlayer::RemotePlayer(char type, ConsoleScreen *screen, Client &client) :
        Player(type,screen), client(client){
}

string RemotePlayer::chooseCell(GameLogic &gameLogic) {
    // receive information from the client.
    char *move= client.receive();
    return (string)move;
}