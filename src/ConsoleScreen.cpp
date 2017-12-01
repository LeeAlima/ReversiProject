
#include "../include/ConsoleScreen.h"

#include <iostream>

ConsoleScreen::ConsoleScreen(){
};

void ConsoleScreen::printEndl() const {
    cout << endl;
}

void ConsoleScreen::printString(string s) const {
    cout << s;
}

ConsoleScreen::~ConsoleScreen(){} ;