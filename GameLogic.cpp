/*
 *  Author: lee alima
 *  ID: 313467441
 */

#include <cstring>
#include <iostream>
#include <sstream>
#include "GameLogic.h"
#include "ConsoleScreen.h"

const int GameLogic::directionTable[8][2] = {
        { 0, 1 },	// up
        { 1, 1 },	// up-left
        { 1, 0 },	// left
        { 1, -1 },	// down-left
        { 0, -1 },	// down
        { -1, -1 },	// down-right
        { -1, 0 },	// right
        { -1, 1 }	// up-right
};

GameLogic::GameLogic(int size,Player *player1,Player *player2,Screen* screen){
    this->my_screen_ = screen;
    /*this->first_player_ = new HumanPlayer('X',my_screen_);
    this->second_player_ = new HumanPlayer('O',my_screen_);*/
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

bool GameLogic::checksIfGameOver(Board &board) const {
    // if all cells are full or the are no possible moves for each side
    if ( board.checkAllCellsFull() ||
            (!checksIfMovesArePossible('X',board)
             && !checksIfMovesArePossible('O',board))){
        return true;
    }
}

bool GameLogic::checksIfMovesArePossible(char type,Board &board) const {
    vector<string> vector_to_check = findPossibleCells(board,type);
    if (vector_to_check.size() == 0){ // if it's empty
        return false;
    }
    return true;
}

vector<string> GameLogic::findPossibleCells(Board & board,char type) const {
    vector<string> vector_of_cells;
    char other_type;
    if (type == 'X'){
        other_type = 'O';
    }
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
                                    string s_1 = findEmptyCellGeneral(i+a,j+b,other_type,a,b,board);
                                    //if the points exists add it to the vector
                                    if ((s_1.compare(empty_word) != 0)) {
                                        vector_of_cells.push_back(s_1);
                                    }
                                /*if (a == 0 && b == -1) {
                                    string s_1 = findEmptyCellGeneral(i,j-1,other_type,0,-1,board);
                                    //if the points exists add it to the vector
                                    if ((s_1.compare(empty_word) != 0)) {
                                        vector_of_cells.push_back(s_1);
                                    }
                                   // cout << "1 is : " + s_1 <<endl;
                                }
                                if (a == 0 && b == 1) {
                                    string s_2 = findEmptyCellGeneral(i,j+1,other_type,0,1,board);
                                    if ( s_2.compare(empty_word) != 0) {
                                        vector_of_cells.push_back(s_2);
                                    }
                                //    cout << "2 is : " + s_2 <<endl;
                                }
                                if (a == -1 && b == 0) {
                                    string s_3 = findEmptyCellGeneral(i-1,j,other_type,-1,0,board);
                                    if (s_3.compare(empty_word) != 0) {
                                        vector_of_cells.push_back(s_3);
                                    }
                                 //   cout << "3 is : " + s_3 <<endl;
                                }
                                if (a == 1 && b == 0) {
                                    string s_4 = findEmptyCellGeneral(i+1,j,other_type,1,0,board);
                                    if (s_4.compare(empty_word) != 0) {
                                        vector_of_cells.push_back(s_4);
                                    }
                                  //  cout << "4 is : " + s_4 <<endl;
                                }
                                if (a == -1 && b == -1) {
                                    string s_5 = findEmptyCellGeneral(i-1,j-1,other_type,-1,-1,board);
                                    if (s_5.compare(empty_word) != 0) {
                                        vector_of_cells.push_back(s_5);
                                    }
                                   // cout << "5 is : " + s_5 <<endl;
                                }
                                if (a == 1 && b == -1) {
                                    string s_6 = findEmptyCellGeneral(i+1,j-1,other_type,1,-1,board);
                                    if (s_6.compare(empty_word) != 0) {
                                        vector_of_cells.push_back(s_6);
                                    }
                                  //  cout << "6 is : " + s_6 <<endl;
                                }
                                if (a == -1 && b == 1) {
                                    string s_7 = findEmptyCellGeneral(i-1,j+1,other_type,-1,1,board);
                                    if (s_7.compare(empty_word) != 0) {
                                        vector_of_cells.push_back(s_7);
                                    }
                                  //  cout << "7 is : " + s_7 <<endl;
                                }
                                if (a == 1 && b == 1) {
                                    string s_8 = findEmptyCellGeneral(i+1,j+1,other_type,1,1,board);
                                    if (s_8.compare(empty_word) != 0) {
                                        vector_of_cells.push_back(s_8);
                                    }
                                   // cout << "8 is : " + s_8 <<endl;
                                }*/
                            }
                        }
                    }
                }
            }
        }
    }
    return this->cutDuplicate(vector_of_cells);
}

string GameLogic::findEmptyCellGeneral(int r, int c,
                                       char t, int rchange, int cchange,Board &board) const{
    int index_row = r;
    int index_col=c;
    for (int i = 1; i<board.getCol();i++){
        if (rchange == -1) {
            index_row =r -i;
        }
        if (rchange == 1) {
            index_row  =r+ i;
        }
        if (cchange == -1){
            index_col =c- i;
        }
        if (cchange == 1){
            index_col =c+ i;
        }
        if (index_row >=0 && index_row < board.getCol()
            && index_col >=0 && index_col < board.getCol()){
            // if an empty cell was found
            if (board.returnCellType(index_row,index_col) == 'E'){
                return "(" + this->toString(index_row) +
                        "," +this->toString(index_col) +")";
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

void GameLogic::makeAMove(int r, int c,
                          char t, int rchange, int cchange,Board &board) const{
    int index_row=r;
    int index_col=c;
    char other_type = 'X';
    if (t == 'X'){
        other_type = 'O';
    }
    for (int i = 0; i<board.getCol();i++){
        if (rchange == -1) {
            index_row = r - i;
        }
        if (rchange == 1) {
            index_row  = r + i;
        }
        if (cchange == -1){
            index_col = c - i;
        }
        if (cchange == 1){
            index_col = c + i;
        }
    if (index_row >=0 && index_row < board.getCol()
        && index_col >=0 && index_col < board.getCol()) {
            if (board.returnCellType(index_row,index_col)
                == other_type){
                int row_new = index_row;
                int col_new = index_col;
                if (rchange == 1){
                    row_new +=1;
                }
                if (rchange== -1){
                    row_new -=1;
                }
                if ( cchange == 1){
                    col_new += 1;
                }
                if (cchange == -1){
                    col_new -= 1;
                }
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
                        int rowLoop = r;
                        int colLoop = c;
                        if (rchange == -1){
                            rowLoop -= j;
                        }
                        if (rchange == 1){
                            rowLoop +=j;
                        }
                        if (cchange == -1){
                            colLoop -= j;
                        }
                        if (cchange == 1){
                            colLoop += j;
                        }
                        board.setCellInBoard(rowLoop,colLoop,t);
                        this->updateScore(board);
                    }
                    return;
                }
            }
        }
    }
}

Board* GameLogic::updateBoard(int x,int y , char type, Board& board) const {
    char other_type;
    if (type == 'X') {
        other_type = 'O';
    }
    if (type == 'O') {
        other_type = 'X';
    } // set the cell in the matrix
    board.setCellInBoard(x,y,other_type);
    for (int a = -1; a < 2; a++) {
        for (int b = -1; b < 2; b++) {
            if ((x + a >= 0) && (x + a < board.getRow())
                && (y + b >= 0) && (y + b < board.getCol())) {
                // found a cell of type
                if (board.returnCellType(x + a, y + b) == type) {
                    if (a == 0 && b == -1) {
                        makeAMove(x,y-1,other_type,0,-1,board);
                    }
                    if (a == 0 && b == 1) {
                        makeAMove(x,y+1,other_type,0,1,board);
                    }
                    if (a == -1 && b == 0) {
                        makeAMove(x-1,y,other_type,-1,0,board);
                    }
                    if (a == 1 && b == 0) {
                        makeAMove(x+1,y,other_type,1,0,board);
                    }
                    if (a == -1 && b == -1) {
                        makeAMove(x-1,y-1,other_type,-1,-1,board);
                    }
                    if (a == 1 && b == -1) {
                        makeAMove(x+1,y-1,other_type,1,-1,board);
                    }
                    if (a == -1 && b == 1) {
                        makeAMove(x-1,y+1,other_type,-1,1,board);
                    }
                    if (a == 1 && b == 1) {
                        makeAMove(x+1,y+1,other_type,1,1,board);
                    }
                }
            }
        }
    }
    return &board;
}

bool GameLogic::checkPlayerMove(string s, char type,Board & board) const {
        vector<string> allPoints = this->findPossibleCells(board,type);
        vector<string>::iterator it;
        for (it = allPoints.begin(); it != allPoints.end(); ++it) {
            if ((*it).compare(s) == 0) { // if the player chois is llegal
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

string GameLogic::toString(int number) const {
        // using stringStram
        stringstream ss;
        ss << number;
        string str = ss.str();
        return str;
    }

void GameLogic::updateScore(Board &board) const {
    // going over the all matrix and counting the number
    // of appearences to each player
    int player_1=0;
    int player_2=0;
    for (int i=0;i< board.getRow();i++) {
        for (int j = 0; j < board.getCol(); j++) {
            if(board.returnCellType(i,j) == 'X'){
                player_1++;
            }
            if(board.returnCellType(i,j) == 'O'){
                player_2++;
            }
        }
    }
    this->first_player_->setScore(player_1);
    this->second_player_->setScore(player_2);
}

int GameLogic::getXScore(Board &b){
    // going over the all matrix and counting the number
    // of appearences to each player
    int player_1=0;
    int player_2=0;
    for (int i=0;i< b.getRow();i++) {
        for (int j = 0; j < b.getCol(); j++) {
            if(b.returnCellType(i,j) == 'X'){
                player_1++;
            }
            if(b.returnCellType(i,j) == 'O'){
                player_2++;
            }
        }
    }
    return player_1-player_2;
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

vector<string> GameLogic::cutDuplicate(vector<string> befor_vec) const {
    vector<string> vector_without_dup;
    vector<string>::iterator iterat;
    for (iterat = befor_vec.begin(); iterat != befor_vec.end(); ++iterat) {
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

Player *GameLogic::getPlayer1(char type) {
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

Board *GameLogic::getGameBoard() {
    return this->my_board_;
}

char GameLogic::getCurrentPlayer() {
    return this->current_Player_;
}
