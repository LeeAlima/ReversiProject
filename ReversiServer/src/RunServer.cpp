//
// Created by lee on 24/12/17.
//

#include <unistd.h>
#include <sys/socket.h>
#include "../include/RunServer.h"
#include "../include/GameRoom.h"

RunServer::RunServer(int clientSocket,vector<Game*> *list) : clientSocket(clientSocket),list_of_games(list) {
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
    for (vector<Game *>::iterator it = list_of_games->begin(); it != list_of_games->end(); ++it) {
        delete *it;
    }
}

void RunServer::startNewGame(vector<string> args) {
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
    list_of_games->push_back(newGame);
    msg.append(okStart);
    sendMessageToClient(msg);
}

void RunServer::listOfGames(vector<string> args) {
    string msg = "";

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
    for (vector<Game *>::iterator it = list_of_games->begin(); it != list_of_games->end(); ++it) {
        if (!strcmp((*it)->getName().c_str(), args[0].c_str()) && (*it)->getStatus() == WAIT) {
            cur_game = *it;
            msg.append(okJoin);
            sendMessageToClient(msg);
            GameRoom gr(cur_game);
            cur_game->setStatus(PLAYING);
            pthread_t *newThread = new pthread_t();
            int rc = pthread_create(newThread, NULL, gr.runGame, (void *) &gr);
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
    string msg = "";
    for (vector<Game *>::iterator it = list_of_games->begin(); it != list_of_games->end(); ++it) {
        if (!strcmp((*it)->getName().c_str(), args[0].c_str())) {
            msg.append(okClose);
            sendMessageToClient(msg);
            list_of_games->push_back(*it);
            return;
        }
    }
    msg.append(notOkClose);
    sendMessageToClient(msg);
}


void RunServer::sendMessageToClient(string msg) {
   /* char *copy = new char[msg.size() + 1];
    strcpy(copy,msg.c_str());
    int n = write(clientSocket, copy, msg.size()+1);
    if (n == -1) {
        cout << "Error writing buffer_local" << endl;
        return;
    }*/
    int n= send(clientSocket,msg.c_str(),msg.length(),0);
    if (n == -1) {
        cout << "Error writing buffer_local" << endl;
        return;
    }
}

void RunServer::setClientSocket(int clientSocket) {
    RunServer::clientSocket = clientSocket;
}
