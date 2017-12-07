
#ifndef EX2_BOARD_H
#define EX2_BOARD_H

#include "Cell.h"

class Board {
public:
    /**
     * this is the constructor for the object.
     * @param row - as the row location.
     * @param col - as the col location.
     * @param screen - as the game's screen to communicate with the users.
     */
    Board(int row, int col);

    /**
     * as the deconstructor - to free all the objects that were allocated.
     */
    ~Board();
    
    /**
     * this method return the board's rows number.
     * @return int - the number of rows
     */
    int getRow() const;
    
    /**
     * this method returns the number of cols.
     * @return int - the number of columns.
     */
    int getCol() const;
    
    /**
     * this method runs over the board's cells and checks
     * if all cells are full.
     * @return true - if the board is full and false otherwise.
     */
    bool checkAllCellsFull() const;
    
    /**
     * this method returns the cell's type given its location.
     * @param r - as the row's location.
     * @param c - as the col's location.
     * @return char - as the cell's type.
     */
    char returnCellType(int r,int c) const;
    
    /**
     * this method set the cell's type.
     * @param r - as the row's location.
     * @param c - as the col's location.
     * @param t - as the type to change to.
     */
    void setCellInBoard(int r, int c,char t) const;

    /**
     * this method returns the board size
     * @return int
     */
    int getSize();

    /**
     * this method copy a board into another board
     * @param source_board - source board
     * @param target_board - target board
     */
    void copyBoardSourceAndTarget(Board &source_board, Board &target_board);

    /**
     * this method converts int to string.
    * @param number - int.
    * @return string.
    */
    string toStringInt(int number) const ;

private:
    int row;
    int col;
    Cell *** my_matrix_;
};

#endif //EX2_BOARD_H