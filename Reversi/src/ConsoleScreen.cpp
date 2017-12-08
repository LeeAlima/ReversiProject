
#include "../include/ConsoleScreen.h"

#include <iostream>
#include <sstream>
#include <unistd.h>

ConsoleScreen::ConsoleScreen(){
};

void ConsoleScreen::printEndl() const {
    cout << endl;
}

void ConsoleScreen::printString(string s) const {
    cout << s;
}

ConsoleScreen::~ConsoleScreen(){} ;


void ConsoleScreen::printBoard(Board &board) const {
    int size = board.getSize();
    for (int z = 0; z < size + 1; z++) {
        if (z == 0) {
            cout << " ";
        } else {
            cout << "| " << z << " ";
        }
    }
    cout << "|" << endl;
    cout << "--";
    for (int i = 0; i < size; i++) {
        cout << "----";
    }
    cout << endl;
    // two loops, this first one symbolizes the columns and the second
    // one symbolizes the lines.
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            if (y == 0) {
                cout << (x + 1);
            }
            cout << "|";
            // printing the cell's type if it's not empty
            if (board.returnCellType(x, y) == 'X'
                || board.returnCellType(x, y) == 'O') {
                cout << " " << board.returnCellType(x, y) << " ";
            } else { // if the cell is empty
                cout << "   ";
            }
        }
        cout << "|" << endl;
        cout << "--";
        for (int i = 0; i < size; i++) {
            cout << "----";
        }
        cout << endl;
    }
}

void ConsoleScreen::printPlayerOrder(char type) const {
    switch (type) {
        case 'O':
            cout << "O: ";
            break;
        case 'X':
            cout << "X: ";
            break;
    }
    cout << "It's your move." << endl;
}

void ConsoleScreen::printPossibleMoves(vector<string> &moves,
                                       bool computer, char type) const {
    // if the player can choose cell for himself print him his options
    if (!computer || type == 'X') {
        cout << "Your possible moves are: ";
        for (int i = 0; i < moves.size(); i++) {
            vector<int> string_change = cutPoint(moves[i]);
            cout << this->fixPointToUser(string_change);
            if (moves[i] != (moves.end() - 1)[i]) {
                cout << ",";
            }
        }
        cout << endl;
    } else { // show a message
        cout << "Computer is thinking..." << endl;
        usleep(1000000);
    }
}

string ConsoleScreen::printPlayerDialog() const {
    // ask the user for a point
    cout << "Please enter your move row,col:";
    string user_cell;
    size_t prev = 0;
    cin >> user_cell;
    // check legality
    while (user_cell.size() > 3 || user_cell.find(",", prev) == -1) {
        cout << "Bad choice, please enter a"
                " new point:" << endl;
        cin.clear();
        cin.ignore(100, '\n');
        cin >> user_cell;
    }
    return user_cell;
}

void ConsoleScreen::printPlayerMove(char type,int num1,int num2) const{
    switch (type) {
        case 'O':
            cout << "'O' chose ("<<num1+1<<","<<num2+1<<")"<<endl;
            break;
        case 'X':
            cout << "'X' chose ("<<num1+1<<","<<num2+1<<")"<<endl;
            break;
        default:
            break;
    }
}

int ConsoleScreen::printOpenMenu() const {
    int option;
    cout << "Welcome to our game!!!!!!" << endl << endl << endl;
    cout << "Choose an opponent type:" << endl;
    cout << "1. a human local player" << endl;
    cout << "2. an AI player" << endl;
    cout << "3. a remote player" << endl;
    do {
        cin >> option;
        // for bad option
        if (option != 1 && option != 2 && option != 3) {
            cout << "Error try again.." << endl;
            cin.clear();
            cin.ignore(100, '\n');
        }
    } while (option != 1 && option != 2 && option != 3);
    return option;
}

void ConsoleScreen::printGameOver(char flag, int score_1, int score_2) const {
    if (flag == '=') {
        cout << "It's a tie!, each player got "<< score_1 << " points."<< endl;
        return;
    }
    // if it's not a tie, print a message of the winner and the player's points
    cout << "Game Is Over, the winner is: " << flag << endl;
    cout << "X: You got " << score_1 << " points" << endl;
    cout << "O: You got " << score_2 << " points" << endl;
}

string ConsoleScreen::fixPointToUser(vector<int> s) const {
    int first_number = s.front() + 1;
    int second_number = s.back() + 1;
    return "(" + toStringInt(first_number) + "," + toStringInt(second_number)
           + ")";
}

string ConsoleScreen::toStringInt(int number) const {
    stringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

vector<int> ConsoleScreen::cutPoint(string user_input) const {
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do {
        // split by ,
        pos = user_input.find(",", prev);
        if (pos == string::npos)
            pos = user_input.length();
        string token = user_input.substr(prev, pos - prev);
        if (!token.empty())
            tokens.push_back(token);
        prev = pos + 1;
    } while (pos < user_input.length() && prev < user_input.length());
    // return the point value
    char front_number1;
    char back_number1;
    if (tokens.front()[0] == '(') {
        front_number1 = tokens.front()[1];
    } else {
        front_number1 = tokens.front()[0];
    }
    back_number1 = tokens.back()[0];
    // converts the string into two numbers
    int first_number = front_number1 - '0';
    int second_number = back_number1 - '0';
    vector<int> point;
    point.push_back(first_number);
    point.push_back(second_number);
    return point;
}