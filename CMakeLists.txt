cmake_minimum_required(VERSION 3.8)
project(ex2)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp Board.cpp Board.h Cell.cpp Cell.h Player.h HumanPlayer.cpp HumanPlayer.h GameLogic.cpp GameLogic.h GameFlow.cpp GameFlow.h Screen.h ConsoleScreen.cpp ConsoleScreen.h AIPlayer.cpp AIPlayer.h)
add_executable(ex2 ${SOURCE_FILES})