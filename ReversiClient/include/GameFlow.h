
#ifndef EX2_GAMEFLOW_H
#define EX2_GAMEFLOW_H

#include "GameLogic.h"
#include "ConsoleScreen.h"
#include "Client.h"

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
     * this is the destructor of the game.
     */
    ~GameFlow();

    /**
     * this method runs the game.
     */
    void run();

    /**
    * this method is called from the constructor
    * and by the user choice initialize the members.
    */
    void setUpGame();

    Client createClientFromFile();

    void handleThirdCase(Client client);

    void startGameCommand(Client client);

    void joinGameCommand(Client client);

    void createGameHuman();

    void createAIGame();

    int getOrder(Client client);

private:
    int size;
    GameLogic* game;
    ConsoleScreen *screen;
    bool computer;
    bool x_player_;
    bool o_player_;

    /**
     * this method prints the scores to the user
     */
    void showScores();
};

#endif //EX2_GAMEFLOW_H