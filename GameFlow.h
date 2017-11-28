
#ifndef EX2_GAMEFLOW_H
#define EX2_GAMEFLOW_H


#include "GameLogic.h"

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
    * this method converts points with the matrix vals
    * to the computer vals - like (1,1) to (0,0)
    * @param user_choice
    * @return
    */
    string fixPointToCom(string user_choice) const;

    /**
    * this method converts points with the computer vals
     * to the matrix val - like (0,0) to (1,1)
     * @param s - as the point
    * @return new string
    */
    string fixPointToUser(vector <int> s) const;

    /**
    * this method is called from the constructor
    * and by the user choice initialize the members.
    */
    void setUpGame();

private:
    int size;
    GameLogic* game;
    Screen* screen;
    bool computer;

    /**
     * this method prints the scores to the user
     */
    void showScores();

    /**
     * this method write the right message to the user, if it's
     * the computer turn then show "computer is thinking", else
     * show the possible moves and ask for one.
     * @param options - vector of possible moves
     * @param type - the type of the player
     */
    void writeMessageToPlayer(vector<string> options, char type);
};

#endif //EX2_GAMEFLOW_H