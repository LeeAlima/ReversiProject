#include <iostream>
#include "../include/GameFlow.h"

using namespace std;

int main(int argc, char *argv[]) {
    GameFlow* myGame = new GameFlow(4);
    myGame->setUpGame();
    myGame->run();
    delete myGame;
}