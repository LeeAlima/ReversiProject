//
// Created by lee on 05/11/17.
//

#ifndef EX2_DSA_H
#define EX2_DSA_H


/*
 *  Author: lee alima
 *  ID: 313467441
 */
#include <iostream>
#include <cstdlib>
#include <sstream>
#include "GameFlow.h"
#include "ConsoleScreen.h"
#include "AIPlayer.h"
#include <unistd.h>


GameFlow::GameFlow(int size):size(size){
    // creating a new game
    this->screen = new ConsoleScreen();;
    setUpGame();
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
            this->screen->printString(this->toStringC(game->getPlayer1('C')->getType())
                                      + ": It's your move!");
            this->screen->printEndl();
        }
        // if the player can make a move
        if (this->game->checksIfMovesArePossible(game->getPlayer1('C')->getType()
                ,*this->game->getBoard())) {
            // print the player's options
            // creating a vector of the options
            vector<string> options =
                    this->game->findPossibleCells(*this->game->getBoard(),game->getPlayer1('C')->getType());
            writeMessageToPlayer(options, this->game->getCurrentPlayer());
            user_choice =this->game->getPlayer1('C')->chooseCell(*this->game);

            choice_to_compare = this->fixPointToCom(user_choice) ;
            if (computer && this->game->getCurrentPlayer() == 'O'){
                choice_to_compare = user_choice;
            }
            // checking the player's move, if it's illegal then asks again
            while (!this->game->checkPlayerMove(choice_to_compare,
                                                game->getPlayer1('C')->getType(),*this->game->getBoard())) {
                cin >> user_choice;
                choice_to_compare = this->fixPointToCom(user_choice) ;
                if (computer && this->game->getCurrentPlayer() == 'O'){
                    choice_to_compare = user_choice;
                }
            }
            // split the input
            vector <string> s = this->cutPoint(user_choice);
            string front_number = s.front();
            string back_number = s.back();
            // converts the string into two numbers
            int first_number = atoi( front_number.c_str());
            int second_number = atoi(back_number.c_str()) ;
            if (computer && this->game->getCurrentPlayer() == 'O'){
                char front_number1 = s.front()[1];
                char back_number1 = s.back()[0];
                first_number = front_number1 - '0' + 1;
                second_number = back_number1 - '0' + 1;
            }
            // updating the board and printing it

            this->game->updateBoard(first_number-1,second_number-1,
                                    this->game->getPlayer1('D')->getType(),*this->game->getBoard());
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
    if (type != 'O' || !(this->computer)){
        vector<string>::iterator it;
        this->screen->printString("Your possible moves are: ");

        for (it = options.begin(); it != options.end(); ++it) {
            vector <string> string_change = this->cutPoint(*it);
            this->screen->printString(this->fixPointToUser(string_change));
            if (it != options.end() - 1) {
                this->screen->printString(",");
            }
        }
        this->screen->printEndl();
    } else {
        this->screen->printString("Computer is thinking...");
        this->screen->printEndl();
        usleep(3000000);

    }
}

void GameFlow::showScores(){
    //when game is over , if it's a tie
    if (this->game->returnsWhoWon() == '='){
        this->screen->printString(
                "It's a tie!, each player got " +
                this->toStringI(this->game->getPlayer1Score())
                + " points.");
        this->screen->printEndl();
        return;
    }
    // if it's not a tie, print a message of the winner and the player's points
    this->screen->printString("Game Is Over, the winner is: " +
                              toStringC(this->game->returnsWhoWon()));
    this->screen->printEndl();
    this->screen->printString("X: You got " + this->toStringI
            (this->game->getPlayer1Score()) + " points");
    this->screen->printEndl();
    this->screen->printString("O: You got " + this->toStringI
            (this->game->getPlayer2Score()) + " points");
}

vector<string> GameFlow::cutPoint(string user_input) const {
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do {
        // split by ,
        pos = user_input.find(",", prev);
        if (pos == string::npos) pos = user_input.length();
        string token = user_input.substr(prev, pos - prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + 1;
    } while (pos < user_input.length() && prev < user_input.length());
    // return the point value
    return tokens;
}

string GameFlow::toStringI(int number) const {
    stringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string GameFlow::toStringC(char c) const {
    stringstream ss;
    string target;
    ss << c;
    ss >> target;
    return target;
}

string GameFlow::fixPointToUser(vector <string> s) const {
    // saving the "numbers"
    char front_number1 = s.front()[1];
    char back_number1 = s.back()[0];
    // converts the string into two numbers
    int first_number = front_number1 - '0';
    int first_number_up = first_number + 1;
    int second_number = back_number1 - '0' ;
    int second_number_up = second_number +1;
    return "(" + this->toStringI(first_number_up)
    + "," + this->toStringI(second_number_up) + ")";
}

string GameFlow::fixPointToCom(string user_choice) const {
    // split the point by ","
    vector <string> s = this->cutPoint(user_choice);
    string front_number = s.front();
    string back_number = s.back();
    // converts the string into two numbers (-1 to fit array show)
    int first_number = atoi( front_number.c_str()) -1 ;
    int second_number = atoi(back_number.c_str()) - 1;
    return "(" +  this->toStringI(first_number)+ ","
           + this->toStringI(second_number) + ")";
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
    while (playerCheck != 1 && playerCheck!=2){
        this->screen->printString("Bad choice,please try again");
        this->screen->printEndl();
        cin >> playerCheck;
    }
    if (playerCheck == 1){
        player1 = new AIPlayer('O',screen);
        player2 = new HumanPlayer('X',screen);
        this->computer = true;
    } else {
        player1 = new HumanPlayer('O',screen);
        player2 = new HumanPlayer('X',screen);
        this->computer = false;
    }
    this->game = new GameLogic(size,player1,player2,screen);
}

#endif //EX2_DSA_H