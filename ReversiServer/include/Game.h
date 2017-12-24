//
// Created by lee on 21/12/17.
//

#ifndef REVERSISERVER_GAME_H
#define REVERSISERVER_GAME_H

#include <string.h>
#include <iostream>

using namespace std;
enum STATUS {
    WAIT, PLAYING, ENDGAME
};
class Game {
public:
    Game();
    ~Game();

    STATUS getStatus() const;

    void setStatus(STATUS status);

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
    STATUS status;
};


#endif //REVERSISERVER_GAME_H
