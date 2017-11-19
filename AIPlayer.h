/*
 *  Author: lee alima
 *  ID: 313467441
 */

#ifndef EX2_AIPLAYER_H
#define EX2_AIPLAYER_H

#include "Player.h"
#include "GameLogic.h"
class AIPlayer : public Player {
public:
    /**
     * constructor of HumanPlayer.
     * @param type - as char ('X' or 'O')
     * @param screen  - as the game screen
     */
    AIPlayer(char type,Screen* screen);

    char getType() const;

    int getScore() const;

    string chooseCell(GameLogic &game) const;

    void setScore(int number);

protected:
    char type;
    int score;
    Screen* player_screen_;

};


#endif //EX2_AIPLAYER_H