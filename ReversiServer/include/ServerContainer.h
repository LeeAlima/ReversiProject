
#ifndef REVERSISERVER_SERVERCONTAINER_H
#define REVERSISERVER_SERVERCONTAINER_H

#include <vector>
#include "Game.h"

class ServerContainer {
public:
    /**
     * constructor for server container
     */
    ServerContainer();

    /**
     * destructor for server container
     */
    ~ServerContainer();

    /**
     * this method adds a Game object to the vector of games
     * @param game - Game object
     */
    void addGame(Game *game);

    /**
     * this method removes a game from the vector of games
     * @param name - the game name
     * @return true if removing was possible and false otherwise
     */
    bool removeGame(string name);

    /**
     * this method remove a client socket number from the vector
     * of clients socket
     * @param client_socket - a number - the client socket that should be removed
     * @return true if removing was possible and false otherwise
     */
    bool removeClientSocket(int client_socket);

    /**
     * this method returns the vector of clients socket(connected)
     * @return vector of int
     */
    vector<int> getClient_sockets() const;

    /**
     * this method add a client socket to the vector of sockets
     * @param client_socket - a number
     */
    void addClientSocket(int client_socket);

    /**
     * this method returns the vector of games
     * @return vector<Game *> - the vector of games
     */
    vector<Game *> *getVecOfGames();

private:
    vector<Game *> *vec_of_games_;
    vector<int> client_sockets_;
};

#endif //REVERSISERVER_SERVERCONTAINER_H