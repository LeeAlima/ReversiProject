
#include <iostream>
#include <gtest/gtest.h>
#include "GameFlow.h"

using namespace std;


int main(int argc, char *argv[]) {
    GameFlow* myGame = new GameFlow(6);
    myGame->setUpGame();
    myGame->play();
    delete myGame;
}
