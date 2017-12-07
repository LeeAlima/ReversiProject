
#include "../include/HumanPlayer.h"

#include <iostream>

using namespace std;


HumanPlayer::HumanPlayer(char type,ConsoleScreen *screen): Player(type,screen){

}

string HumanPlayer::fixPointToCom(string user_choice) const {
    // split the point by ","
    vector<int> s = player_screen_->cutPoint(user_choice);
    return "(" + this->player_screen_->toStringInt(s.front() - 1) + ","
           + this->player_screen_->toStringInt(s.back() - 1) + ")";
}

string HumanPlayer::chooseCell(GameLogic &gameLogic) {
    if (gameLogic.checksIfMovesArePossible(type,*gameLogic.getBoard())){
        vector<string> options = gameLogic.findPossibleCells(
                *gameLogic.getBoard(), gameLogic.getPlayer('C')->getType());
        player_screen_->printPossibleMoves(options, false,type);

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
    return "NO MOVE";
}


