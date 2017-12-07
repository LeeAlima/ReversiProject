
#ifndef EX2_CONSOLESCREEN_H
#define EX2_CONSOLESCREEN_H

#include <vector>
#include "Board.h"

class ConsoleScreen {
public:
    /**
     * this is the constructor for the object.
     */
    ConsoleScreen();

    /**
     * deconstructor for the object
     */
    ~ConsoleScreen();

    /**
     * this method prints string to the console.
     * @param s - as the string to print.
     */
    void printString(string s) const;

    /**
     * this method prints empty line to the console.
     */
    void printEndl() const;

    void printBoard(Board &board) const;
    void printPossibleMoves(vector<string> &moves, bool computer,char type) const;

    string printPlayerDialog() const;
    void printPlayerMove(char type,int num1,int num2) const;
    int printOpenMenu() const;
    void printGameOver(char flag, int score1, int score2) const;
    string fixPointToUser(vector<int> s) const;
    string toStringInt(int number) const;
    vector<int> cutPoint(string user_input) const;
    void printPlayerOrder(char type) const;
};

#endif //EX2_CONSOLESCREEN_H