
#include "../include/Board.h"

#include <iostream>
#include <sstream>

using namespace std;

Board::Board(int row,int col):
        row(row), col(col) {
    int mid_row = row/2 -1;
    int mid_col = col/2 -1;
    // creating the matrix
    this->my_matrix_ = new Cell**[row];
    // creating the rows
    for (int i = 0;i<row;i++){
        this->my_matrix_[i] = new Cell*[col];
    }
    // creating the all matrix
    for (int j = 0; j < row; j++) {
        for (int z = 0; z < col; z++) {
            this->my_matrix_[j][z] = new Cell('E');
        }
    }
    // initialize the 4 inner cells.
    this->my_matrix_[mid_row][mid_col]->setType('O');
    this->my_matrix_[mid_row][mid_col+1]->setType('X');
    this->my_matrix_[mid_row+1][mid_col+1]->setType('O');
    this->my_matrix_[mid_row+1][mid_col]->setType('X');
}

Board::~Board() {
    // freeing all of the cells
    for (int j = 0; j < row; j++) {
        for (int z = 0; z<col; z++){
            delete my_matrix_[j][z];
        }
    }
    // freeing all of the rows
    for (int i = 0; i<row; i++){
        delete [] my_matrix_[i];
    }
    // freeing the all matrix
    delete [] my_matrix_;
}

int Board ::getRow() const{
    return this->row;
}

int Board::getCol() const {
    return this->col;
}

void Board::copyBoardSourceAndTarget(Board &source_board, Board &target_board){
    for (int i= 0;i<target_board.getSize() ;i++ ){
        for (int j = 0; j < target_board.getSize(); j++) {
            target_board.setCellInBoard(i,j,source_board.returnCellType(i,j));
        }
    }
};

bool Board::checkAllCellsFull() const {
    // going over all the matrix cells
    for (int i= 0;i<col ;i++ ){
        for (int j = 0; j < col; j++) {
            if (my_matrix_[j][i]->getType() == 'E'){
                return false;
            }
        }
    }
    // if all cells are full
    return true;
}

char Board::returnCellType(int r,int c) const{
    return my_matrix_[r][c]->getType();
}

void Board::setCellInBoard(int r, int c, char t) const {
    this->my_matrix_[r][c]->setType(t);
}

string Board::toStringInt(int number) const {
    stringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}


int Board::getSize() {
    return this->row;
}
