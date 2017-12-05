
#ifndef EX2_GAMEFLOW_H
#define EX2_GAMEFLOW_H


#include "../include/GameLogic.h"
#include "ConsoleScreen.h"

/**
 * this class runs the all game.
 */

class GameFlow {
public:
    /**
     * this is the constructor of the class.
     * @param size - as the board size.
     */
    GameFlow(int size1);

    /**
     * this is the deconstructor of the game.
     */
    ~GameFlow();

    /**
     * this method runs the game.
     */
    void play();

    /**
    * this method is called from the constructor
    * and by the user choice initialize the members.
    */
    void setUpGame();

private:
    int size;
    GameLogic* game;
    ConsoleScreen *screen;
    bool computer;

    /**
     * this method prints the scores to the user
     */
    void showScores();

};

#endif //EX2_GAMEFLOW_H