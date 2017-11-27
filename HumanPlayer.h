/*
 *  Lee alima 313467441
 *  Omer havakok 203345087
 */

#ifndef EX2_HUMANPLAYER_H
#define EX2_HUMANPLAYER_H

#include "GameLogic.h"
#include "Player.h"

class HumanPlayer : public Player {
public:
    /**
     * constructor of HumanPlayer.
     * @param type - as char ('X' or 'O')
     * @param screen  - as the game screen
     */
    HumanPlayer(char type,Screen* screen);

    char getType() const;

    int getScore() const;

    string chooseCell(GameLogic &gameLogic) ;

    void setScore(int number);

protected:
    char type;
    int score;
    Screen* player_screen_;

};


#endif //EX2_HUMANPLAYER_H