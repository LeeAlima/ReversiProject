//
// Created by lee on 24/12/17.
//

#include <unistd.h>
#include <sys/socket.h>
#include "../include/RunServer.h"
#include "../include/GameRoom.h"

RunServer::RunServer(int clientSocket, ServerContainer *serverContainer) : clientSocket(clientSocket) ,serverContainer(serverContainer) {
    notOkStart = string("2");
    okStart = string("1");
    okJoin = string("3");
    notSuchGameJoin = string("4");
    gameIsPlaying = string("5");
    okClose = string("6");
    notOkClose = string("7");
    notOkList = string("8");
}

RunServer::~RunServer() {
    vector<Game*> *list_of_games = serverContainer->getVecOfGames();
    for (vector<Game *>::iterator it = list_of_games->begin(); it != list_of_games->end(); ++it) {
        delete *it;
    }
}

void RunServer::startNewGame(vector<string> args) {
    vector<Game*> *list_of_games = serverContainer->getVecOfGames();
    string msg = "";
    for (vector<Game *>::iterator it = list_of_games->begin(); it != list_of_games->end(); ++it) {

        if (!strcmp((*it)->getName().c_str(), args[0].c_str())) {
            msg.append(notOkStart);
            sendMessageToClient(msg);
            return;
        }

    }
    // create a new game
    Game *newGame = new Game();
    newGame->setName(args[0]);
    newGame->setFirst_socket(clientSocket);
    newGame->setStatus(WAIT);
    serverContainer->addGame(newGame);
    msg.append(okStart);
    sendMessageToClient(msg);
}

void RunServer::listOfGames(vector<string> args) {
    string msg = "";
    vector<Game*> *list_of_games = serverContainer->getVecOfGames();
    msg.append("The available games:\n");
    for (vector<Game *>::iterator it = list_of_games->begin(); it != list_of_games->end(); ++it) {
        if ((*it)->getStatus() == WAIT) {
            msg.append((*it)->getName());
            msg.append("\n");
        }
    }
    if (msg == "") {
        msg.append(notOkList);
    }
    sendMessageToClient(msg);
}

void RunServer::joinToGame(vector<string> args) {
    Game *cur_game = NULL;
    string msg = "";
    vector<Game*> *list_of_games = serverContainer->getVecOfGames();

    for (vector<Game *>::iterator it = list_of_games->begin(); it != list_of_games->end(); ++it) {
        if (!strcmp((*it)->getName().c_str(), args[0].c_str()) && (*it)->getStatus() == WAIT) {
            (*it)->setSecond_socket(clientSocket);
            cur_game = *it;
            msg.append(okJoin);
            sendMessageToClient(msg);
            GameRoom *gr = new GameRoom(cur_game, serverContainer);
            cur_game->setStatus(PLAYING);
            pthread_t *newThread = new pthread_t();
            int rc = pthread_create(newThread, NULL, gr->runGame, (void *) gr);
            if (rc) {
                cout << "Error: unable to create thread, " << rc << endl;
                pthread_exit(&newThread);
            }
            return;
        } else if (!strcmp((*it)->getName().c_str(), args[0].c_str()) && (*it)->getStatus() == PLAYING) {
            msg.append(gameIsPlaying);
            sendMessageToClient(msg);
            return;
        }
    }
    msg.append(notSuchGameJoin);
    sendMessageToClient(msg);
    return;
}

void RunServer::closeGame(vector<string> args) {
    bool del = serverContainer->removeGame(args[0]);
    string msg = "";
    if (del){
        msg.append(okClose);
    } else {
        msg.append(notOkClose);
    }
    sendMessageToClient(msg);
}


void RunServer::sendMessageToClient(string msg) {
    int n = send(clientSocket, msg.c_str(), msg.length(), 0);
    if (n == -1) {
        cout << "Error writing buffer_local" << endl;
        return;
    }
}