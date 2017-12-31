//
// Created by omer on 28/12/17.
//

#include "../include/ServerContainer.h"

ServerContainer::ServerContainer() {
    this->list_of_games = new vector<Game*>;
}

ServerContainer::~ServerContainer() {
    delete list_of_games;
}

void ServerContainer::addGame(Game *game) {
    this->list_of_games->push_back(game);
}

bool ServerContainer::removeGame(string name) {
    for (vector<Game *>::iterator it = list_of_games->begin(); it != list_of_games->end(); ++it) {
        if (!strcmp((*it)->getName().c_str(), name.c_str())) {
            list_of_games->erase(it);
            return true;
        }
    }
    return false;
}
void ServerContainer::addClientSocket(int client_socket) {
    this->client_sockets.push_back(client_socket);
}

bool ServerContainer::removeClientSocket(int client_socket) {
    for (vector<int>::iterator it = client_sockets.begin(); it != client_sockets.end(); ++it) {
        if (*it==client_socket) {
            client_sockets.erase(it);
            return true;
        }
    }
    return false;
}


vector<Game *> *ServerContainer::getVecOfGames() {
    return list_of_games;
}

vector<int> ServerContainer::getClient_sockets() const {
    return client_sockets;
}


