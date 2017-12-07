
#ifndef EX2_HUMANPLAYER_H
#define EX2_HUMANPLAYER_H

#include "Player.h"

/*#include "../include/GameLogic.h"
#include "../include/Player.h"
#include "../include/ConsoleScreen.h"*/

class HumanPlayer : public Player {
public:
    /**
     * constructor of HumanPlayer.
     * @param type - as char ('X' or 'O')
     * @param screen  - as the game screen
     */
    HumanPlayer(char type,ConsoleScreen *screen);

    string chooseCell(GameLogic &gameLogic) ;

private:
    string fixPointToCom(string user_choice) const;

};


#endif //EX2_HUMANPLAYER_H