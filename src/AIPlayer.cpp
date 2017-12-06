
#include "../include/AIPlayer.h"

using namespace std;

AIPlayer::AIPlayer(char type, ConsoleScreen *screen): Player(type,screen){
}


string AIPlayer::chooseCell(GameLogic &game) {
    if (game.checksIfMovesArePossible('O',*game.getBoard())){
        // find possible moves to the computerchecksIfMovesArePossible
        vector<string> vec_of_options=game.findPossibleCells(*game.getBoard(),'O');
        player_screen_->printPossibleMoves(vec_of_options, true,type);
        vector<string> vec_sec;
        int max = - game.getBoard()->getSize()^2;
        int min = game.getBoard()->getSize()^2;
        string result_max,result_min;
        // going over all of the possible computer options
        if (vec_of_options.size() == 1){
            return vec_of_options.front();
        }
        result_max = vec_of_options.front();
        for (int i=0; i<vec_of_options.size();i++){
            // create a board with vals of the current board
            Board* board_after_com_move = new Board(game.getBoard()->getSize()
                    ,game.getBoard()->getSize());
            game.getBoard()->copyBoardSourceAndTarget(
                    *game.getBoard(),*board_after_com_move);
            vector<int> point_coordinate = player_screen_->cutPoint(vec_of_options[i]);
            int O_x_coordinate = point_coordinate[0];
            int O_y_coordinate = point_coordinate[1];
            // update board
            board_after_com_move = game.updateBoard(
                    O_x_coordinate,O_y_coordinate,'X',*board_after_com_move);
            // find possible moves to the human player
            vec_sec = game.findPossibleCells(*board_after_com_move,'X');
            int X_x_coordinate,X_y_coordinate;
            // if there are not possible moves for X
            if (vec_sec.size()==0){
                max = game.getScoresDifference(*board_after_com_move);
            } else {
                // going over the human player possible moves
                for (int t = 0; t<vec_sec.size();t++){
                    max = -game.getBoard()->getSize()^2;
                    // create board with the board_after_com_move values
                    Board* board_after_human_move =new Board(game.getBoard()->
                            getSize(),game.getBoard()->getSize());
                    game.getBoard()->copyBoardSourceAndTarget(
                            *board_after_com_move,*board_after_human_move);
                    vector<int> second_vec_cor = player_screen_->cutPoint(vec_sec[t]);
                    X_x_coordinate = second_vec_cor[0];
                    X_y_coordinate = second_vec_cor[1];
                    // update the game
                    board_after_human_move = game.updateBoard(X_x_coordinate
                            , X_y_coordinate,'O',*board_after_human_move);
                    // save the max difference
                    if (game.getScoresDifference(*board_after_human_move) > max){
                        max = game.getScoresDifference(*board_after_human_move);
                        result_max = vec_of_options[i];
                    }
                    delete board_after_human_move;
                }
            }
            if (max < min){
                min = max;
                result_min = result_max;
            } // save the lowest between the max
            delete board_after_com_move;
        }
        return result_min;
    }
    return "NO MOVE";
}
