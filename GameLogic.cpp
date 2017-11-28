/*
 *  Lee alima 313467441
 *  Omer havakok 203345087
 */

#include <cstring>
#include <iostream>
#include "GameLogic.h"

GameLogic::GameLogic(int size,Player *player1,Player *player2,Screen* screen){
    this->my_screen_ = screen;
    this->first_player_ = player1;
    this->second_player_ = player2;
    this->my_board_ = new Board(size,size, * my_screen_);
    this->current_Player_ = 'O';
}

GameLogic::~GameLogic() {
    delete my_screen_;
    delete first_player_;
    delete second_player_;
    delete my_board_;
}

char GameLogic::returnsWhoWon() const {
    int player_1_score = first_player_->getScore();
    int player_2_score = second_player_->getScore();
    if (player_1_score == player_2_score ){ // if it's a tie
        return '=';
    }
    if (player_1_score > player_2_score){
        return first_player_->getType();
    }
    return second_player_->getType();
}

bool GameLogic::checksIfGameOver(Board &board) {
    // if all cells are full or the are no possible moves for each side
    if ( board.checkAllCellsFull() ||
            (!checksIfMovesArePossible('X',board)
             && !checksIfMovesArePossible('O',board))){
        return true;
    }
}

bool GameLogic::checksIfMovesArePossible(char type,Board &board) {
    vector<string> vector_to_check = findPossibleCells(board,type);
    if (vector_to_check.size() == 0){ // if it's empty
        return false;
    }
    return true;
}

vector<string> GameLogic::findPossibleCells(Board & board,char type) {
    vector<string> vector_of_cells;
    char other_type = 'O';
    if (type == 'O'){
        other_type = 'X';
    }
    // going over the all matrix
    for (int i=0;i< board.getRow();i++) {
        for (int j = 0; j < board.getCol(); j++) {
            // if the cell is on the current player type
            if (board.returnCellType(i, j) == type) {
                // looking for the other type near it
                for (int a = -1; a < 2; a++) {
                    for (int b = -1; b < 2; b++) {
                        if ((i + a >= 0) && (i+a < board.getRow())
                            && (j + b >= 0)
                            && (j+b < board.getCol())) {
                            // found other type cell
                            if (board.returnCellType(i + a, j + b)
                                == other_type) {
                                string empty_word = "(";
                                    string point = findEmptyCellGeneral(
                                            i+a,j+b,other_type,a,b,board);
                                    //if the points exists add it to the vector
                                    if ((point.compare(empty_word) != 0)) {
                                        vector_of_cells.push_back(point);
                                    }
                            }
                        }
                    }
                }
            }
        }
    }
    return this->cutDuplicate(vector_of_cells);
}

string GameLogic::findEmptyCellGeneral(int r, int c, char t, int row_change,
                                       int col_change,Board &board) {
    int index_row = r;
    int index_col=c;
    for (int i = 1; i<board.getCol();i++){
        changeNumber(index_row,row_change,r,i);
        changeNumber(index_col,col_change,c,i);
        // check if in limits
        if (index_row >=0 && index_row < board.getCol()
            && index_col >=0 && index_col < board.getCol()){
            // if an empty cell was found
            if (board.returnCellType(index_row,index_col) == 'E'){
                return "(" + this->getBoard()->toStringInt(index_row) +
                       "," + this->getBoard()->toStringInt(index_col) +")";
            } // if the cell is on the same player's type
            if (board.returnCellType(index_row,index_col) == t ){
                continue;
            } // if the cell is on the other player's type
            if (board.returnCellType(index_row,index_col) != t){
                break;
            }
        }
    }
    return "(";
}

void GameLogic::makeAMove(int r, int c, char t, int row_change,
                          int col_change,Board &board) {
    int index_row=r;
    int index_col=c;
    char other_type = 'X';
    if (t == 'X'){
        other_type = 'O';
    }
    for (int i = 0; i< board.getCol();i++){
        // change the index variables, add or reduce i from r\c
        changeNumber(index_row,row_change,r,i);
        changeNumber(index_col,col_change,c,i);
    if (index_row >=0 && index_row < board.getCol()
        && index_col >=0 && index_col < board.getCol()) {
            if (board.returnCellType(index_row,index_col)
                == other_type){
                int row_new = index_row;
                int col_new = index_col;
                row_new +=row_change;
                col_new +=col_change;
                if (row_new >=0  && row_new < board.getRow()
                        && col_new >=0 && col_new < board.getCol()){
                    // if an empty cell was found
                    if (board.returnCellType(row_new,col_new)
                        == 'E') {
                        return;
                    }
                } // if the cell is out of the matrix
                if (row_new < 0 || row_new >= board.getRow()
                    || col_new < 0 || col_new >= board.getCol()){
                    return;
                } // if access is possible checks its type
                if (board.returnCellType(row_new,col_new) == t){
                    for ( int j = 0;j<=i+1;j++){
                        int row_loop = r;
                        int col_loop = c;
                        changeNumber(row_loop,row_change,row_loop,j);
                        changeNumber(col_loop,col_change,col_loop,j);
                        board.setCellInBoard(row_loop,col_loop,t);
                        this->updateScore(board);
                    }
                    return;
                }
            }
        }
    }
}

void GameLogic::changeNumber(int &number,int flag,
                             int default_number,int add_number){
    if (flag == 1){
        number = default_number + add_number;
    } if (flag == -1) {
        number = default_number - add_number;
    }
}

Board* GameLogic::updateBoard(int x,int y , char type, Board& board) {
    char other_type = 'O';
    if (type == 'O') {
        other_type = 'X';
    } // set the cell in the matrix
    board.setCellInBoard(x,y,other_type);
    for (int a = -1; a < 2; a++) {
        for (int b = -1; b < 2; b++) {
            if ((x + a >= 0) && (x + a < board.getRow())
                && (y + b >= 0) && (y + b < board.getCol())) {
                // make a move
                if (board.returnCellType(x + a, y + b) == type) {
                    makeAMove(x+a,y+b,other_type,a,b,board);
                }
            }
        }
    }
    return &board;
}

bool GameLogic::checkPlayerMove(string user_input, char type,Board & board) {
        vector<string> allPoints = this->findPossibleCells(board,type);
        vector<string>::iterator it;
        // go over all of the possible moves and compare
        // the user choice to them
        for (it = allPoints.begin(); it != allPoints.end(); ++it) {
            if ((*it).compare(user_input) == 0) { // if the player choice is llegal
                return true;
            }
        }
        // ask the player to enter a new point
        this->my_screen_->printString("Bad choise, please enter a new point:");
        this->my_screen_->printEndl();
        return false;
    }

Board* GameLogic::getBoard() {
        return my_board_;
    }

void GameLogic::updateScore(Board &board) const {
    // going over the all matrix and counting the number
    // of appearences to each player
    int player_1=0;
    int player_2=0;
    for (int i=0;i< board.getRow();i++) {
        for (int j = 0; j < board.getCol(); j++) {
            if(board.returnCellType(i,j) == 'O'){
                player_1++;
            }
            if(board.returnCellType(i,j) == 'X'){
                player_2++;
            }
        }
    }
    this->first_player_->setScore(player_1);
    this->second_player_->setScore(player_2);
}

int GameLogic::getScoresDifference(Board &b){
    // going over the all matrix and counting the number
    // of appearences to each player
    int player_X=0;
    int player_O=0;
    for (int i=0;i< b.getRow();i++) {
        for (int j = 0; j < b.getCol(); j++) {
            if(b.returnCellType(i,j) == 'X'){
                player_X++;
            }
            if(b.returnCellType(i,j) == 'O'){
                player_O++;
            }
        }
    }
    return player_X-player_O;
}

int GameLogic::getPlayer2Score() const {
    return this->second_player_->getScore();
}

int GameLogic::getPlayer1Score() const {
    return this->first_player_->getScore();
}

Screen* GameLogic::getScreen() {
    return this->my_screen_;
}

vector<string> GameLogic::cutDuplicate(vector<string> vector_before) const {
    vector<string> vector_without_dup;
    vector<string>::iterator iterat;
    for (iterat = vector_before.begin(); iterat != vector_before.end(); ++iterat) {
        bool flag = false;
        vector<string>::iterator it2;
        for (it2 = vector_without_dup.begin();
             it2 != vector_without_dup.end(); ++it2){
            string s1 = *iterat;
            string s2 = *it2;
            if ( (s1.compare(s2) == 0) ){
                // if the point already appeard
                flag = true;
            }
        }
        if (!flag){ // if the point didn't appear already
            vector_without_dup.push_back(*iterat);
        }
    }
    return vector_without_dup;
}

void GameLogic::changePlayer() {
    if (this->current_Player_ == 'O'){
        this->current_Player_ = 'X';
    } else {
        this->current_Player_ = 'O';
    }
}

Player *GameLogic::getPlayer(char type) {
    // check the type and return the right player
    if (type == 'X') {
        return this->second_player_;
    }
    if (type == 'O'){
        return this->first_player_;
    }
    if (type == 'C'){
        if (current_Player_ == 'X'){
            return this->second_player_;
        }
        return this->first_player_;
    }
    if (type == 'D'){
        if (current_Player_ == 'X'){
            return this->first_player_;
        }
        return this->second_player_;
    }
}

char GameLogic::getCurrentPlayer() {
    return this->current_Player_;
}

vector<int> GameLogic::cutPoint(string user_input) const {
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
    // return the point value
    char front_number1 ;
    char back_number1 ;
    if (tokens.front()[0] == '('){
        front_number1 = tokens.front()[1];
    } else {
        front_number1 = tokens.front()[0];
    }
    back_number1 = tokens.back()[0];
    // converts the string into two numbers
    int first_number = front_number1 - '0';
    int second_number = back_number1 - '0' ;
    vector<int> point;
    point.push_back(first_number);
    point.push_back(second_number);
    return point;
}
