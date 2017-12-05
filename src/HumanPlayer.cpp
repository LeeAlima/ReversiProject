
#include "../include/HumanPlayer.h"

#include <iostream>

using namespace std;


HumanPlayer::HumanPlayer(char type,ConsoleScreen *screen):
        score(2), type(type), player_screen_(screen){
}

char HumanPlayer::getType() const {
    return this->type;
}

int HumanPlayer::getScore() const {
    return this->score;
}

string HumanPlayer::chooseCell(GameLogic &gameLogic) {
    string user_cell = this->player_screen_->printPlayerDialog();
    string choice_to_compare = fixPointToCom(user_cell);
    while (!gameLogic.checkPlayerMove(choice_to_compare, getType(),
                                      *gameLogic.getBoard())) {
        cin.clear();
        cin.ignore(100, '\n');
        this->player_screen_->printString("Bad choice");
        this->player_screen_->printEndl();
        user_cell = this->player_screen_->printPlayerDialog();
        choice_to_compare = fixPointToCom(user_cell);
    }
    return choice_to_compare;
}

string HumanPlayer::fixPointToCom(string user_choice) const {
    // split the point by ","
    vector<int> s = player_screen_->cutPoint(user_choice);
    return "(" + this->player_screen_->toStringInt(s.front() - 1) + ","
           + this->player_screen_->toStringInt(s.back() - 1) + ")";
}

void HumanPlayer::setScore(int number) {
    this->score = number;
}