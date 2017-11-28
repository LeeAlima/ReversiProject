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
    vector<string> vec_of_options=game.findPossibleCells(*game.getBoard(),'O');
    vector<string> vec_sec;
    int max = - game.getBoard()->getSize()^2;
    int min = game.getBoard()->getSize()^2;
    string result_max,result_min;
    // going over all of the possible computer options
    for (int i=0; i<vec_of_options.size();i++){
        // create a board with vals of the current board
        Board* board_after_com_move = new Board(game.getBoard()->getSize()
                ,game.getBoard()->getSize(),*game.getScreen());
        game.getBoard()->copyBoardSourceAndTarget(
                *game.getBoard(),*board_after_com_move);
        vector<int> point_coordinate = game.cutPoint(vec_of_options[i]);
        int O_x_coordinate = point_coordinate[0];
        int O_y_coordinate = point_coordinate[1];
        // update board
        board_after_com_move = game.updateBoard(
                O_x_coordinate,O_y_coordinate,'X',*board_after_com_move);
        // find possible moves to the human player
        vec_sec = game.findPossibleCells(*board_after_com_move,'X');
        int X_x_coordinate,X_y_coordinate;
        // going over the human player possible moves
        for (int t = 0; t<vec_sec.size();t++){
            // create board with the board_after_com_move values
            Board* board_after_human_move =new Board(game.getBoard()->getSize()
                    ,game.getBoard()->getSize(),*game.getScreen());
            game.getBoard()->copyBoardSourceAndTarget(
                    *game.getBoard(),*board_after_human_move);
            vector<int> second_vec_cor = game.cutPoint(vec_sec[t]);
            X_x_coordinate = second_vec_cor[0];
            X_y_coordinate = second_vec_cor[1];
            // update the game
            board_after_human_move = game.updateBoard(
                    X_x_coordinate,X_y_coordinate,'O',*board_after_human_move);
            // save the max difference
            if (game.getScoresDifference(*board_after_human_move) > max){
                max = game.getScoresDifference(*board_after_human_move);
                result_max = vec_of_options[i];
            }
            // save the lowest between the max
            if (max < min){
                min = max;
                result_min = result_max;
            }
            delete board_after_human_move;
        }
        delete board_after_com_move;
    }
    return result_max;
}

void AIPlayer::setScore(int number) {
    this->score = number;
}