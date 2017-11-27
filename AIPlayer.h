/*
 *  Lee alima 313467441
 *  Omer havakok 203345087
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

    string chooseCell(GameLogic &game) ;

    void setScore(int number);
    vector<int> cutAPoint(string user_input);

protected:
    char type;
    int score;
    Screen* player_screen_;

};


#endif //EX2_AIPLAYER_H