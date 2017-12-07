
#ifndef EX2_AIPLAYER_H
#define EX2_AIPLAYER_H

#include "Player.h"

class AIPlayer : public Player {
public:
    /**
     * constructor of HumanPlayer.
     * @param type - as char ('X' or 'O')
     * @param screen  - as the game screen
     */
    AIPlayer(char type,ConsoleScreen *screen);

    string chooseCell(GameLogic &game) ;

};

#endif //EX2_AIPLAYER_H