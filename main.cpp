/*
 *  Lee alima 313467441
 *  Omer havakok 203345087
 */

#include <iostream>
#include <gtest/gtest.h>
#include "GameFlow.h"

using namespace std;


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    GameFlow* myGame = new GameFlow(8);
    myGame->play();
    delete myGame;
}
