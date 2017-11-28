
#include <iostream>
#include "ConsoleScreen.h"

ConsoleScreen::ConsoleScreen(){
};

void ConsoleScreen::printEndl() const {
    cout << endl;
}

void ConsoleScreen::printString(string s) const {
    cout << s;
}

ConsoleScreen::~ConsoleScreen(){} ;