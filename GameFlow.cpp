
#ifndef EX2_DSA_H
#define EX2_DSA_H

#include <iostream>
#include "GameFlow.h"
#include "ConsoleScreen.h"
#include "AIPlayer.h"
#include <unistd.h>

GameFlow::GameFlow(int size):size(size){
    // creating a new game
    this->screen = new ConsoleScreen();
}

GameFlow::~GameFlow() {
    delete game;
}

void GameFlow::play() {
    // printing the board
    this->game->getBoard()->printBoard();
    string user_choice;
    string choice_to_compare;
    // as long as the game is not over
    while (!this->game->checksIfGameOver(*this->game->getBoard())){
        if (game->getCurrentPlayer()!='O'||!(this->computer)){
            this->screen->printString(this->game->getBoard()->toStringChar(
                    game->getPlayer('C')->getType()) + ": It's your move!");
            this->screen->printEndl();
        }
        // if the player can make a move
        if (this->game->checksIfMovesArePossible(
                game->getPlayer('C')->getType(),*this->game->getBoard())) {
            // print the player'point_coordinate options
            // creating a vector of the options
            vector<string> options =
                    this->game->findPossibleCells(*this->game->getBoard()
                            , game->getPlayer('C')->getType());
            writeMessageToPlayer(options, this->game->getCurrentPlayer());
            user_choice = this->game->getPlayer('C')->chooseCell(*this->game);
            string befor_change = user_choice;
            choice_to_compare = this->fixPointToCom(user_choice) ;
            if (computer && this->game->getCurrentPlayer() == 'O'){
                choice_to_compare = user_choice;
            }
            // checking the player'point_coordinate move,
            // if it'point_coordinate illegal then asks again
            while (!this->game->checkPlayerMove(choice_to_compare
                    ,game->getPlayer('C')->getType(),*this->game->getBoard())){
                cin >> user_choice;
                choice_to_compare = this->fixPointToCom(user_choice) ;
                if (computer && this->game->getCurrentPlayer() == 'O'){
                    choice_to_compare = user_choice;
                }
            }
            // split the input
            vector <int> point_coordinate = this->game->cutPoint(user_choice);
            int first_number = point_coordinate.front();
            int second_number = point_coordinate.back();
            if (computer && this->game->getCurrentPlayer() == 'O'){
                first_number = point_coordinate.front() + 1;
                second_number = point_coordinate.back() + 1;
            }
            if (computer && this->game->getCurrentPlayer() == 'O'){
                string message = "'O' chose (" + this->game->getBoard()->
                        toStringInt(first_number)+ ","+this->game->getBoard()->
                        toStringInt(second_number) + ")";
                this->screen->printString(message);
                this->screen->printEndl();
                this->screen->printEndl();
            }
            // updating the board and printing it
            this->game->updateBoard(first_number-1,second_number-1
                    , this->game->getPlayer('D')->getType()
                    ,*this->game->getBoard());
            this->screen->printEndl();
            this->game->getBoard()->printBoard();
        }
        else { // if no move is possible
            this->screen->printString("No moves are possible for you");
            this->screen->printEndl();
        }
        this->game->changePlayer();
    }
    showScores();
}

void GameFlow::writeMessageToPlayer(vector<string> options, char type){
    // show possible moves
    if (type != 'O' || !(this->computer)){
        vector<string>::iterator it;
        this->screen->printString("Your possible moves are: ");
        for (it = options.begin(); it != options.end(); ++it) {
            vector <int> string_change = this->game->cutPoint(*it);
            this->screen->printString(this->fixPointToUser(string_change));
            if (it != options.end() - 1) {
                this->screen->printString(",");
            }
        }
        this->screen->printEndl();
    } else { // show a message
        this->screen->printString("Computer is thinking...");
        this->screen->printEndl();
        usleep(1000000);
    }
}

void GameFlow::showScores(){
    //when game is over , if it's a tie
    if (this->game->returnsWhoWon() == '='){
        this->screen->printString(
                "It's a tie!, each player got " +
                this->game->getBoard()->toStringInt
                        (this->game->getPlayer1Score()) + " points.");
        this->screen->printEndl();
        return;
    }
    // if it's not a tie, print a message of the winner and the player's points
    this->screen->printString("Game Is Over, the winner is: " + this->game->
            getBoard()->toStringChar(this->game->returnsWhoWon()));
    this->screen->printEndl();

    this->screen->printString("X: You got " + this->game->getBoard()->
            toStringInt(this->game->getPlayer1Score()) + " points");
    this->screen->printEndl();
    this->screen->printString("O: You got " + this->game->getBoard()->
            toStringInt(this->game->getPlayer2Score()) + " points");
}

string GameFlow::fixPointToUser(vector <int> s) const {
    int first_number = s.front() +1;
    int second_number = s.back() +1;
    return "(" + this->game->getBoard()->toStringInt(first_number) +"," +
            this->game->getBoard()->toStringInt(second_number) + ")";
}

string GameFlow::fixPointToCom(string user_choice) const {
    // split the point by ","
    vector <int> s = this->game->cutPoint(user_choice);
    return "(" +  this->game->getBoard()->toStringInt(s.front()-1) + ","
           + this->game->getBoard()->toStringInt(s.back()-1) + ")";
}

void GameFlow::setUpGame() {
    this->screen->printString("Welcom to our game!!!!!!");
    this->screen->printEndl();
    this->screen->printString("Please choose game:");
    this->screen->printEndl();
    this->screen->printString("for a game with a computer please enter 1");
    this->screen->printEndl();
    this->screen->printString("for a game with a human please enter 2");
    this->screen->printEndl();
    int playerCheck;
    cin >> playerCheck;
    Player *player1, *player2;
    while (playerCheck != 1 && playerCheck != 2 ){
        this->screen->printString("Bad choice,please try again");
        this->screen->printEndl();
        cin.clear();
        cin.ignore(100,'\n');
        cin >> playerCheck;
    }
    if (playerCheck == 1){
        player1 = new HumanPlayer('X',screen);
        player2 = new AIPlayer('O',screen);
        this->computer = true;
    } else {
        player1 = new HumanPlayer('X',screen);
        player2 = new HumanPlayer('O',screen);
        this->computer = false;
    }
    this->game = new GameLogic(size,player1,player2,screen);
}

#endif //EX2_DSA_H