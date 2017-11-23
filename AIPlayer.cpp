/*
 *  Author: lee alima
 *  ID: 313467441
 */

#include <iostream>
#include <cstdlib>
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

string AIPlayer::chooseCell(GameLogic &game)  {
    vector<string> vecOfOptions = game.findPossibleCells(*game.getBoard(),'O');
    vector<string> vecSec;
    int max = - game.getBoard()->getSize()^2;
    int min = game.getBoard()->getSize()^2;
    string resultMax;
    string resultMin;
    for (int i=0; i<vecOfOptions.size();i++){
        Board* boardAfterComMove = new Board(game.getBoard()->getSize()
                ,game.getBoard()->getSize(),*game.getScreen());
        game.getBoard()->copyBoardSourceAndTarget(*game.getBoard(),*boardAfterComMove);
        vector<int> firstVec = cutAPoint(vecOfOptions[i]);
        int xCor = firstVec[0];
        int yCor = firstVec[1];
        boardAfterComMove = game.updateBoard(xCor,yCor,'X',*boardAfterComMove);
        //boardAfterComMove->printBoard();
        vecSec = game.findPossibleCells(*boardAfterComMove,'X');
        int XCOR;
        int YCOR;
        for (int t = 0; t<vecSec.size();t++){
            Board* boardAfterHumanMove = new Board(game.getBoard()->getSize()
                    ,game.getBoard()->getSize(),*game.getScreen());
            game.getBoard()->copyBoardSourceAndTarget(*game.getBoard(),*boardAfterHumanMove);
            vector<int> secondVecCor = cutAPoint(vecSec[t]);
            XCOR = secondVecCor[0];
            YCOR = secondVecCor[1];
            boardAfterHumanMove = game.updateBoard(XCOR,YCOR,'O',*boardAfterHumanMove);
            if (game.getXScore(*boardAfterHumanMove) > max){
                max = game.getXScore(*boardAfterHumanMove);
                resultMax = vecOfOptions[i];
            }
            if (max < min){
                min = max;
                resultMin = resultMax;
            }
            delete boardAfterHumanMove;
        }
        delete boardAfterComMove;
    }
    return resultMax;

}

void AIPlayer::setScore(int number) {
    this->score = number;
}

vector<int> AIPlayer::cutAPoint(string user_input) {
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do {
        // split by ,
        pos = user_input.find(",", prev);
        if (pos == string::npos) pos = user_input.length();
        string token = user_input.substr(prev, pos - prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + 1;
    } while (pos < user_input.length() && prev < user_input.length());

    char front_number1 = tokens.front()[1];
    char back_number1 = tokens.back()[0];
    // converts the string into two numbers
    int first_number = front_number1 - '0';
    int second_number = back_number1 - '0' ;
    vector<int> point;
    point.push_back(first_number);
    point.push_back(second_number);
    return point;
}
