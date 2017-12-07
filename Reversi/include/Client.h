//
// Created by lee on 06/12/17.
//

#ifndef REVERSI_CLIENT_H
#define REVERSI_CLIENT_H

#include <string>
#include <iostream>
using namespace std;

class Client {
public:
    Client(const char *serverIP, int serverPort);
    int connectToServer();
    void send(char *user_choice) const;
    char* receive() const;
private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
};



#endif //REVERSI_CLIENT_H
