/*
 *  Lee alima 313467441
 *  Omer havakok 203345087
 */

#include <iostream>
#include "GameLogic.h"
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
    // find possible moves to the computer
    vector<string> vecOfOptions = game.findPossibleCells(*game.getBoard(),'O');
    vector<string> vecSec;
    int max = - game.getBoard()->getSize()^2;
    int min = game.getBoard()->getSize()^2;
    string resultMax;
    string resultMin;
    // going over all of the possible computer options
    for (int i=0; i<vecOfOptions.size();i++){
        // create a board with vals of the current board
        Board* boardAfterComMove = new Board(game.getBoard()->getSize()
                ,game.getBoard()->getSize(),*game.getScreen());
        game.getBoard()->copyBoardSourceAndTarget(*game.getBoard(),*boardAfterComMove);
        vector<int> firstVec = cutAPoint(vecOfOptions[i]);
        int xCor = firstVec[0];
        int yCor = firstVec[1];
        // update board
        boardAfterComMove = game.updateBoard(xCor,yCor,'X',*boardAfterComMove);
        // find possible moves to the human player
        vecSec = game.findPossibleCells(*boardAfterComMove,'X');
        int XCOR;
        int YCOR;
        // going over the human player possible moves
        for (int t = 0; t<vecSec.size();t++){
            // create board with the boardAfterComMove values
            Board* boardAfterHumanMove = new Board(game.getBoard()->getSize()
                    ,game.getBoard()->getSize(),*game.getScreen());
            game.getBoard()->copyBoardSourceAndTarget(*game.getBoard(),*boardAfterHumanMove);
            vector<int> secondVecCor = cutAPoint(vecSec[t]);
            XCOR = secondVecCor[0];
            YCOR = secondVecCor[1];
            // update the game
            boardAfterHumanMove = game.updateBoard(XCOR,YCOR,'O',*boardAfterHumanMove);
            // save the max difference
            if (game.getScoresDifference(*boardAfterHumanMove) > max){
                max = game.getScoresDifference(*boardAfterHumanMove);
                resultMax = vecOfOptions[i];
            }
            // save the lowest between the max
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
