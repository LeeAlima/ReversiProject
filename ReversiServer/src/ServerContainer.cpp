//
// Created by omer on 28/12/17.
//

#include "../include/ServerContainer.h"

ServerContainer::ServerContainer() {
    this->vec_of_games_ = new vector<Game *>;
}

ServerContainer::~ServerContainer() {
    delete vec_of_games_;
}

void ServerContainer::addGame(Game *game) {
    this->vec_of_games_->push_back(game);
}

bool ServerContainer::removeGame(string name) {
    // going over the vector of games and look for a game with the same name
    // as the name received in this method
    for (vector<Game *>::iterator it = vec_of_games_->begin();
         it != vec_of_games_->end(); ++it) {
        if (!strcmp((*it)->getName().c_str(), name.c_str())) {
            // if a game was found than erase it and return true
            vec_of_games_->erase(it);
            return true;
        }
    }
    // no game with the same name was found
    return false;
}

void ServerContainer::addClientSocket(int client_socket) {
    this->client_sockets_.push_back(client_socket);
}

bool ServerContainer::removeClientSocket(int client_socket) {
    // going over the vector of integers and look for a number
    // as the same as the client socket
    for (vector<int>::iterator it = client_sockets_.begin();
         it != client_sockets_.end(); ++it) {
        if (*it == client_socket) {
            // if a number was found than erase if and return true
            client_sockets_.erase(it);
            return true;
        }
    }
    // there is no a number as the client_socket in the vec of int
    return false;
}

vector<Game *> *ServerContainer::getVecOfGames() {
    return vec_of_games_;
}

vector<int> ServerContainer::getClient_sockets() const {
    return client_sockets_;
}