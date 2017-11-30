
#include <iostream>
#include "HumanPlayer.h"

using namespace std;


HumanPlayer::HumanPlayer(char type,Screen* screen):
        score(2), type(type), player_screen_(screen){
}

char HumanPlayer::getType() const {
    return this->type;
}

int HumanPlayer::getScore() const {
    return this->score;
}

string HumanPlayer::chooseCell(GameLogic &gameLogic) {
    string user_cell;
    // ask for cell
    this->player_screen_->printString("please choose a cell");
    this->player_screen_->printEndl();
    // scan what the user typed
    cin >> user_cell;
    size_t prev = 0;
    while (user_cell.size() >3 || user_cell.find(",",prev) == -1){
        this->player_screen_->printString("Bad choice, please enter a"
                                                  " new point:");
        this->player_screen_->printEndl();
        cin.clear();
        cin.ignore(100,'\n');
        cin >> user_cell;
    }
    return user_cell;
}

void HumanPlayer::setScore(int number) {
    this->score = number;
}