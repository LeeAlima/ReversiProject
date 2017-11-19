/*
 *  Author: lee alima
 *  ID: 313467441
 */

#include <iostream>
#include "GameLogic.h"
#include "Board.h"
#include "Player.h"
#include "AIPlayer.h"


using namespace std;

AIPlayer::AIPlayer(char type,Screen* screen):
        score(2), type(type), player_screen_(screen){
}

char AIPlayer::getType() const {
    return this->type;
}

int AIPlayer::getScore() const {
    return this->score;
}

string AIPlayer::chooseCell(GameLogic &game) const {
    Board *b;
    b= game.getBoard();
    vector<string> vecFirst = game.findPossibleCells(*b,'O');
    vector<string> vecSec;
    // change with func to size^2
    int min = 64;
    string result;
    for (int i=0; i<vecFirst.size();i++){
        int xCor;
        int yCor;
        b = game.updateBoard(xCor,yCor,'X',*b);
        vecSec = game.findPossibleCells(*b,'X');
        int XCOR;
        int YCOR;
        for (int j = 0; j<vecSec.size();j++){
            b = game.updateBoard(XCOR,YCOR,'O',*b);
            if (game.getXScore(*b) < min){
                min = game.getXScore(*b);
                result = vecFirst[i];
            }
        }
        b = game.getBoard();
    }
    return result;

}

void AIPlayer::setScore(int number) {
    this->score = number;
}
