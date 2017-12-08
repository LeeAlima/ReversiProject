
#ifndef EX2_DSA_H
#define EX2_DSA_H

#include <fstream>
#include "../include/GameFlow.h"
#include "../include/AIPlayer.h"
#include "../include/HumanPlayer.h"
#include "../include/Client.h"
#include "../include/RemotePlayer.h"
#include "../include/LocalPlayer.h"

GameFlow::GameFlow(int size):size(size){
    // creating a new game
    this->screen = new ConsoleScreen();
}

GameFlow::~GameFlow() {
    delete game;
}

void GameFlow::run() {
    Board *board = this->game->getBoard();
    Player *player;
    // printing the board
    screen->printBoard(*board);
    string user_choice,choice_to_compare;
    // as long as the game is not over
    while (!this->game->checksIfGameOver(*this->game->getBoard())) {
        board = this->game->getBoard();
        player = (game->getPlayer('C'));
        // ask for point if it's needed
        if (!(computer) || player->getType() == 'X' ) {
            bool b = x_player_;
            if (player->getType() == 'O'){
                b = o_player_;
            }
            screen->printPlayerOrder(b,player->getType());
        }
        // scan a point
        user_choice = this->game->getPlayer('C')->chooseCell(*this->game);
        // if the player can make a move
        if (user_choice.compare("NO MOVE")){
            // split the input
            vector<int> point_coordinate = screen->cutPoint(user_choice);
            int first_number = point_coordinate.front();
            int second_number = point_coordinate.back();
            // print move
            screen->printPlayerMove(player->getType(),
                                    first_number, second_number);
            // updating the board and printing it
            this->game->updateBoard(first_number , second_number ,
                                    this->game->getPlayer('D')->getType(),
                                    *this->game->getBoard());
            this->screen->printEndl();
            this->screen->printBoard(*board);
        }
 else { // if no move is possible
            this->screen->printString("No moves are possible for you");
            this->screen->printEndl();
        }
        this->game->changePlayer();
    }
    showScores();
}

void GameFlow::showScores() {
    screen->printGameOver(this->game->returnsWhoWon()
            , this->game->getPlayer1Score(), game->getPlayer2Score());
}

void GameFlow::setUpGame() {
    this->screen = new ConsoleScreen();
    int playerCheck = this->screen->printOpenMenu();
    Player *player1, *player2;
    switch (playerCheck) {
        // for a game with a human
        case 1:
            player1 = new HumanPlayer('X', screen);
            player2 = new HumanPlayer('O', screen);
            this->computer = false;
            this->x_player_ = true;
            this->o_player_ = true;
            break;
            // for a game with the computer
        case 2 :
            player1 = new HumanPlayer('X', screen);
            player2 = new AIPlayer('O', screen);
            this->computer = true;
            this->x_player_ = true;
            this->o_player_ = true;
            break;
        case 3 :{
            // connect by client
            ifstream inFile;
            inFile.open("config_client.txt");
            string ip;
            int port;
            inFile >> ip;
            inFile >> port;
            cout<<ip<<endl;
            cout<<port<<endl;
            try{
                Client client(ip.c_str(),port);
                int num_of_player=client.connectToServer();
                if(num_of_player==1){
                    player1 =new LocalPlayer('X',screen,client);
                    player2= new RemotePlayer('O',screen,client);
                    this->x_player_ = true;
                    this->o_player_ = false;
                } else {
                    player1=new RemotePlayer('X',screen,client);
                    player2=new LocalPlayer('O',screen,client);
                    this->x_player_ = false;
                    this->o_player_ = true;
                }
            }catch (const char *msg) {
                this->screen->printString("Failed to connect to server. Reason: ");
                this->screen->printString(msg);
                this->screen->printEndl();
                return;
            }
            break;
        }
        default:
            break;

    } // create the game
    this->game = new GameLogic(size, player1, player2, screen);
}
#endif //EX2_DSA_H