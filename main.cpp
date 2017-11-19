/*
 *  Author: lee alima
 *  ID: 313467441
 */

#include <iostream>
#include "GameFlow.h"

using namespace std;


int main() {
    cout<<"omer 2 change"<<endl;
    GameFlow* myGame = new GameFlow(8);
    myGame->play();
    delete myGame;
}
