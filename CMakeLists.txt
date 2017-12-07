cmake_minimum_required(VERSION 3.9)
project(ReversiProject)

set(CMAKE_CXX_STANDARD 11)

add_executable(ReversiProject
        include/AIPlayer.h
        include/Board.h
        include/Cell.h
        include/ConsoleScreen.h
        include/GameFlow.h
        include/GameLogic.h
        include/HumanPlayer.h
        include/Player.h
        src/AIPlayer.cpp
        src/Board.cpp
        src/Cell.cpp
        src/ConsoleScreen.cpp
        src/GameFlow.cpp
        src/GameLogic.cpp
        src/HumanPlayer.cpp
        src/main.cpp
        UnitTest/gtest_main.cpp
        UnitTest/TestFixture.cpp)
