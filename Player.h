/*
 *  Lee alima 313467441
 *  Omer havakok 203345087
 */

#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <string>
#include "Screen.h"
#include "GameLogic.h"

using namespace std;

/**
 * this is an abstract class - in the way, different
 * kinds of players can be created.
 */
class GameLogic;
class Player {
public:
    /**
     * this method return the player type.
     * @return char - as the player's type.
     */
    virtual char getType() const = 0;

    /**
     * this method return the player score.
     * @return int - as the player's score.
     */
    virtual int getScore() const = 0;

    /**
     * this method asks the user for a cell and returns it.
     * @param gameLogic - the game in order to use the methods of gameLogic.
     * @return string - as the cell's location.
     */
    virtual string chooseCell(GameLogic &gameLogic) = 0;

    /**
     * this method sets the player's score
     * @param number - as the score number
     */
    virtual void setScore(int number) = 0;



protected:
    char type;
    int score;
    Screen* player_screen_;
};


#endif //EX2_PLAYER_H