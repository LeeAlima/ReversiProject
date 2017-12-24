//
// Created by lee on 24/12/17.
//

#include <unistd.h>
#include "../include/RunServer.h"

RunServer::RunServer(int clientSocket) : clientSocket(clientSocket) {

}

RunServer::~RunServer() {


}

void RunServer::startNewGame(vector<string> args) {
    string msg = "";
    for (std::list<Game>::iterator it=list_of_games.begin(); it != list_of_games.end(); ++it){
        if (!strcmp((*it).getName().c_str(),args[0].c_str())){
            msg.append("-1");
            sendMessageToClient(msg);
            return;
        }
    }
    // create a new game
    Game *newGame = new Game();
    newGame->setName(args[0]);
    newGame->setFirst_socket(clientSocket);
    newGame->setStatus(WAIT);
    list_of_games.push_back(*newGame);
    msg.append(args[0] + " has been created successfully!\n waiting for another player...");
    sendMessageToClient(msg);

}

void RunServer::listOfGames(vector<string> args) {
    string msg = "";
    if (list_of_games.empty()){
        msg.append("-2");
    } else {
    msg.append("The available games:\n");
    for (std::list<Game>::iterator it=list_of_games.begin(); it != list_of_games.end(); ++it){
        if ((*it).getStatus() == WAIT){
            msg.append((*it).getName());
            msg.append("\n");
            }
        }
    }
    sendMessageToClient(msg);
}

void RunServer::joinToGame(vector<string> args) {

}

void RunServer::closeGame(vector<string> args) {

}

void RunServer::playGame(vector<string> args) {

}

void RunServer::sendMessageToClient(string msg) {

    //const char *buffer_local= msg.c_str();

    int n = write(clientSocket, msg.c_str(),msg.length());
    if (n == -1) {
        cout << "Error writing buffer_local" << endl;
        return;
    }
}
