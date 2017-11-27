/*
 *  Lee alima 313467441
 *  Omer havakok 203345087
 */

#include <iostream>
#include "ConsoleScreen.h"

ConsoleScreen::ConsoleScreen() { //empty constructor
}


void ConsoleScreen::printEndl() const {
    cout << endl;
}

void ConsoleScreen::printString(string s) const {
    cout << s;
}

ConsoleScreen::~ConsoleScreen() {
}
