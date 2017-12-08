#include "../include/Player.h"

Player::Player(char type,ConsoleScreen *screen):
        score(2), type(type), player_screen_(screen){
}

char Player::getType() const {
    return this->type;
}

int Player::getScore() const {
    return this->score;
}


void Player::setScore(int number) {
    this->score = number;
}

Player::~Player() {
}
