
#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <string>

#include "GameLogic.h"
#include "ConsoleScreen.h"

using namespace std;

/**
 * this is an abstract class - in the way, different
 * kinds of players can be created.
 */


class GameLogic;

class Player {
public:
    Player(char type,ConsoleScreen *screen);
    ~Player();
    /**
     * this method return the player type.
     * @return char - as the player's type.
     */
     char getType() const ;

    /**
     * this method return the player score.
     * @return int - as the player's score.
     */
    int getScore() const ;

    /**
 * this method sets the player's score
 * @param number - as the score number
 */
    void setScore(int number);

    /**
     * this method asks the user for a cell and returns it.
     * @param gameLogic - the game in order to use the methods of gameLogic.
     * @return string - as the cell's location.
     */
    virtual string chooseCell(GameLogic &gameLogic) = 0;



protected:
    char type;
    int score;
    ConsoleScreen *player_screen_;
};


#endif //EX2_PLAYER_H