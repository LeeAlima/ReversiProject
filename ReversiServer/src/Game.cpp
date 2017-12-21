//
// Created by lee on 21/12/17.
//

#include "../include/Game.h"

const string &Game::getName() const {
    return name;
}

void Game::setName(const string &name) {
    Game::name = name;
}

int Game::getFirst_socket() const {
    return first_socket;
}

void Game::setFirst_socket(int first_socket) {
    Game::first_socket = first_socket;
}

int Game::getSecond_socket() const {
    return second_socket;
}

void Game::setSecond_socket(int second_socket) {
    Game::second_socket = second_socket;
}
