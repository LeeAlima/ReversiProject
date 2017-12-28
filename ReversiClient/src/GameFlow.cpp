#ifndef EX2_DSA_H
#define EX2_DSA_H

#include <fstream>
#include <cstring>
#include <unistd.h>
#include "../include/GameFlow.h"
#include "../include/AIPlayer.h"
#include "../include/HumanPlayer.h"
#include "../include/Client.h"
#include "../include/RemotePlayer.h"
#include "../include/LocalPlayer.h"

# define OkStart 1
# define NotOkStart 2
# define OkJoin 3
# define NotSuchAGameJoin 4
# define GameIsPlaying 5
# define OkClose 6
# define NotOkClose 7
# define NotOkList 8

GameFlow::GameFlow(int size) : size(size) {
}

GameFlow::~GameFlow() {
    delete game;
}

void GameFlow::run() {
    Board *board = this->game->getBoard();
    Player *player;
    // printing the board
    screen->printBoard(*board);
    string user_choice, choice_to_compare;
    // as long as the game is not over
    while (!this->game->checksIfGameOver(*this->game->getBoard())) {
        board = this->game->getBoard();
        player = (game->getPlayer('C'));
        // ask for point if it's needed
        if (!(computer) || player->getType() == 'X') {
            bool b = x_player_;
            if (player->getType() == 'O') {
                b = o_player_;
            }
            screen->printPlayerOrder(b, player->getType());
        }
        // scan a point
        user_choice = this->game->getPlayer('C')->chooseCell(*this->game);
        // if the player can make a move
        if (user_choice.compare("NO MOVE")) {
            // split the input
            vector<int> point_coordinate = screen->cutPoint(user_choice);
            int first_number = point_coordinate.front();
            int second_number = point_coordinate.back();
            // print move
            screen->printPlayerMove(player->getType(),
                                    first_number, second_number);
            // updating the board and printing it
            this->game->updateBoard(first_number, second_number,
                                    this->game->getPlayer('D')->getType(),
                                    *this->game->getBoard());
            this->screen->printEndl();
            this->screen->printBoard(*board);
        } else { // if no move is possible
            this->screen->printNoMoveOrder(player->getType());
        }
        this->game->changePlayer();
    }
    showScores();
}

void GameFlow::showScores() {
    screen->printGameOver(this->game->returnsWhoWon(), this->game->getPlayer1Score(), game->getPlayer2Score());
}


void GameFlow::setUpGame() {
    this->screen = new ConsoleScreen();
    int playerCheck = this->screen->printOpenMenu();
    switch (playerCheck) {
        // for a game with a human
        case 1:
            createGameHuman();
            break;
            // for a game with the computer
        case 2 :
            createAIGame();
            break;
        case 3 : try {
            ifstream inFile;
            inFile.open("config_client.txt");
            string ip;
            int port;
            inFile >> ip;
            inFile >> port;
            Client client(ip.c_str(), port);
            // לתקן!!!!!
            handleThirdCase(client);

        } catch (const char *msg) {
        this->screen->printString("Failed to connect to server."
                                          " Reason: ");
        this->screen->printString(msg);
        this->screen->printEndl();
        return;
    }
    }
}

pair<const char *, int> GameFlow::createClientFromFile() {
    ifstream inFile;
    inFile.open("config_client.txt");
    string ip;
    int port;
    inFile >> ip;
    inFile >> port;
    return make_pair(ip.c_str(), port);
    //Client client(ip.c_str(),port);
    //return client;
}

void GameFlow::handleThirdCase(Client client) {
    bool not_ok = true;
    while (not_ok) {
        client.connectToServer();
        pair<string, string> result = screen->handleSubMenu();
        string user_sub_option = result.first;
        string gameName = result.second;
        user_sub_option.append("\0");
        client.sendMessage(user_sub_option.c_str());
        string msgFromServer = client.reciveMessage();
        if (msgFromServer.size() != 1) {
            screen->printString(msgFromServer);
            continue;
        } else {
            int option = atoi(msgFromServer.c_str());
            switch (option) {
                case OkStart:
                    startGameCommand(client, gameName);
                    return;
                case NotOkStart:
                    screen->printString("this name has been already token");
                    screen->printEndl();
                    continue;
                case OkJoin:
                    joinGameCommand(client, gameName);
                    return;
                case NotSuchAGameJoin:
                    screen->printString("there is not such a game");
                    screen->printEndl();
                    continue;
                case GameIsPlaying:
                    screen->printString("this game is being played by 2 players");
                    screen->printEndl();
                    continue;
                case OkClose:
                    return;
                case NotOkClose:
                    screen->printString("there is not such a game");
                    screen->printEndl();
                    continue;
                case NotOkList:
                    screen->printString("The list is empty");
                    screen->printEndl();
                    continue;

            }
        }
    }
}

void GameFlow::startGameCommand(Client client, string name) {
    string message = "";
    screen->printString("Waiting for another player to join");
    screen->printEndl();
    // לעטוף בטריי קאטצ מהקייס עצמו
    int number = getOrder(client);
    string wait = "Your number is:" + screen->toStringInt(number);
    screen->printString(wait);
    screen->printEndl();
    Player *player1 = new LocalPlayer('X', screen, client);
    Player *player2 = new RemotePlayer('O', screen, client);
    this->x_player_ = true;
    this->o_player_ = false;
    this->game = new GameLogic(size, player1, player2, screen);
    run();
    client.sendMove("END");
}

void GameFlow::joinGameCommand(Client client, string name) {
    string message = "";
    int number = getOrder(client);
    string wait = "Your number is:" + screen->toStringInt(number);
    screen->printString(wait);
    screen->printEndl();
    Player *player1 = new RemotePlayer('X', screen, client);
    Player *player2 = new LocalPlayer('O', screen, client);
    this->x_player_ = false;
    this->o_player_ = true;
    this->game = new GameLogic(size, player1, player2, screen);
    run();
    client.sendMove("END");
}

void GameFlow::createGameHuman() {
    Player *player1 = new HumanPlayer('X', screen);
    Player *player2 = new HumanPlayer('O', screen);
    this->computer = false;
    this->x_player_ = true;
    this->o_player_ = true;
    this->game = new GameLogic(size, player1, player2, screen);
    run();
}

void GameFlow::createAIGame() {
    Player *player1 = new HumanPlayer('X', screen);
    Player *player2 = new AIPlayer('O', screen);
    this->computer = true;
    this->x_player_ = true;
    this->o_player_ = true;
    this->game = new GameLogic(size, player1, player2, screen);
    run();
}

int GameFlow::getOrder(Client client) {
    int num_of_player;
    int client_socket_ = client.getClientSocket();
    int n = read(client_socket_, &num_of_player, sizeof(num_of_player));
    if (n == -1) {
        throw "Error of reading from socket";
    }
    return num_of_player;

}

#endif //EX2_DSA_H