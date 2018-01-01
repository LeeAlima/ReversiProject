
#ifndef REVERSISERVER_RUNSERVER_H
#define REVERSISERVER_RUNSERVER_H

#include <iostream>
#include <vector>
#include <list>
#include "Game.h"
#include "ServerContainer.h"
#include "../include/GameRoom.h"

using namespace std;

/**
 * This class is being called from the commands classes and
 * activates the right method.
 */
class RunServer {
public:
    /**
     * constructor to RunServer
     * @param clientSocket - int as the client socket number
     * @param server_container - as a pointer to the server container
     */
    RunServer(int clientSocket);

    /*
     * destructor
     */
    virtual ~RunServer();

    /**
     * this methos sends message to the client
     * @param msg - string as the message to senc
     */
    void sendMessageToClient(string msg);

    /**
     * this method starts a new game by creating a Game object and
     * setting its members. Than the method adds the game to the list
     * of games in the server containter class
     * If starting a game is possible than sends OkStart to the client,
     * else, sends him notOkStart.
     * @param args - vector of string with the game details
     */
    void startNewGame(vector<string> args);

    /**
     * this method goes over the list of games (receiving it from the
     * class container) and creates a message of it.
     * Than, the method sends the message to the user.
     * If the list is empty than sends notOkList.
     * @param args - an empty vector.
     */
    void listOfGames(vector<string> args);

    /**
     * this method goes over the list of games (receiving it from the
     * class container) and checks if there is an available game with
     * the same name the user chose.
     * If he can join the game than sends okJoin, If there are
     * already 2 player playing the game than sends gameIsPlaying,
     * and if there is not a game with this name than sends notSuchGameJoin.
     * @param args - vector of string with the game details
     */
    void joinToGame(vector<string> args);

    /**
     * This method tries to remove a game in the server container.
     * If it succeeded than it sends okClose , else notOkClose.
     * @param args - vector of string with the game details
     */
    void closeGame(vector<string> args);

private:
    ServerContainer *server_container_;
    int client_socket_;
    string not_ok_start_;
    string ok_start_;
    string ok_join_;
    string not_such_game_join_;
    string game_is_playing_;
    string ok_close_;
    string not_ok_close_;
    string not_ok_list_;
};

#endif //REVERSISERVER_RUNSERVER_H
