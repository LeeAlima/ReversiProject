
#include <unistd.h>
#include <sys/socket.h>
#include "../include/RunServer.h"

RunServer::RunServer(int clientSocket) :
        client_socket_(clientSocket){
    server_container_=ServerContainer::getInstance();
    ok_start_ = string("1");
    not_ok_start_ = string("2");
    ok_join_ = string("3");
    not_such_game_join_ = string("4");
    game_is_playing_ = string("5");
    ok_close_ = string("6");
    not_ok_close_ = string("7");
    not_ok_list_ = string("8");
}

RunServer::~RunServer() {
    vector<Game *> *list_of_games = server_container_->getVecOfGames();
    for (vector<Game *>::iterator it = list_of_games->begin();
         it != list_of_games->end(); ++it) {
        delete *it;
    }
}

void RunServer::startNewGame(vector<string> args) {
    vector<Game *> *list_of_games = server_container_->getVecOfGames();
    string game_name = args[0];
    string msg = "";
    // go over the list og games
    for (vector<Game *>::iterator it = list_of_games->begin();
         it != list_of_games->end(); ++it) {
        // if there is already a game with this name than sends not_ok_start_
        if (!strcmp((*it)->getName().c_str(), game_name.c_str())) {
            msg.append(not_ok_start_);
            sendMessageToClient(msg);
            return;
        }
    }
    // create a new game and sets its name, status and first client socket.
    Game *newGame = new Game();
    newGame->setName(game_name);
    newGame->setFirst_socket(client_socket_);
    newGame->setStatus(WAIT);
    // add game to the server_container_
    server_container_->addGame(newGame);
    // send ok_start_
    msg.append(ok_start_);
    sendMessageToClient(msg);
}

void RunServer::listOfGames(vector<string> args) {
    string list = "";
    vector<Game *> *list_of_games = server_container_->getVecOfGames();
    // go over the list of games
    for (vector<Game *>::iterator it = list_of_games->begin();
         it != list_of_games->end(); ++it) {
        // it the game status is waiting, than append its name to the string
        if ((*it)->getStatus() == WAIT) {
            list.append((*it)->getName());
            list.append("\n");
        }
    } // if the string is empty (there are no games waiting)
    if (list == "") { // send not_ok_list_
        list.append(not_ok_list_);
        sendMessageToClient(list);
        return;
    }
    // send the the list to the user
    string msg = "";
    msg.append("The available games:\n");
    msg.append(list);
    sendMessageToClient(msg);
}

void RunServer::joinToGame(vector<string> args) {
    Game *cur_game = NULL;
    string game_name = args[0];
    string msg = "";
    vector<Game *> *list_of_games = server_container_->getVecOfGames();
    // go over the list of games
    for (vector<Game *>::iterator it = list_of_games->begin();
         it != list_of_games->end(); ++it) {
        // if there is a waiting game with this name
        if (!strcmp((*it)->getName().c_str(), game_name.c_str())
            && (*it)->getStatus() == WAIT) {
            // set second socket and send ok_join_
            (*it)->setSecond_socket(client_socket_);
            cur_game = *it;
            msg.append(ok_join_);
            sendMessageToClient(msg);
            // create a new GameRoom
            GameRoom *gr = new GameRoom(cur_game);
            cur_game->setStatus(PLAYING);
            pthread_t *newThread = new pthread_t();
            // run the game in a thread
            int rc = pthread_create(newThread, NULL, gr->runGame, (void *) gr);
            if (rc) { // can't create a thread
                cout << "Error: unable to create thread, " << rc << endl;
                pthread_exit(&newThread);
            }
            return;
            // if there is a game with this name but it's being playing
        } else if (!strcmp((*it)->getName().c_str(), game_name.c_str()) &&
                   (*it)->getStatus() == PLAYING) {
            // send game_is_playing_
            msg.append(game_is_playing_);
            sendMessageToClient(msg);
            return;
        }
    } // if there is not a game with such name, than send not_such_game_join_
    msg.append(not_such_game_join_);
    sendMessageToClient(msg);
    return;
}

void RunServer::closeGame(vector<string> args) {
    string game_name = args[0];
    // try to remove game from the list
    bool del = server_container_->removeGame(game_name);
    string msg = "";
    if (del) { // if removing accured, send ok_close_
        msg.append(ok_close_);
    } else { // if removing wasn't possible, send not_ok_close_
        msg.append(not_ok_close_);
    }
    sendMessageToClient(msg);
}

void RunServer::sendMessageToClient(string msg) {
    int n = send(client_socket_, msg.c_str(), msg.length(), 0);
    if (n == -1) { // error
        cout << "Error writing buffer_local" << endl;
        return;
    }
}