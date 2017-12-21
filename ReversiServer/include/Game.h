//
// Created by lee on 21/12/17.
//

#ifndef REVERSISERVER_GAME_H
#define REVERSISERVER_GAME_H

#include <string.h>
#include <iostream>

using namespace std;

class Game {
public:
    Game();
    ~Game();

    const string &getName() const;

    void setName(const string &name);

    int getFirst_socket() const;

    void setFirst_socket(int first_socket);

    int getSecond_socket() const;

    void setSecond_socket(int second_socket);

private:
    string name;
    int first_socket;
    int second_socket;
};


#endif //REVERSISERVER_GAME_H
