
#ifndef REVERSI_CLIENT_H
#define REVERSI_CLIENT_H

#include <string>
#include <iostream>
using namespace std;

class Client {
public:
    /**
     * this is the constructor of Client
     * @param serverIP - as the server IP
     * @param serverPort - as the server port
     */
    Client(const char *serverIP, int serverPort);

    /**
     * this method connect to the server and return the number of player
     * @return int - as the number of player (1/2)
     */
    int connectToServer();

    /**
     * this method writes user choice to the socket
     * @param user_choice - the input
     */
    void sendMove(const char *user_choice) const;

    /**
     * this method receive a point from the socket
     * @return char* - the point
     */
    char* receive() const;

    int getClientSocket() const;

    string reciveMessage() const;

    //void sendMessage(string s) const ;


private:
    const char *server_IP_;
    int server_port_;
    int client_socket_;

};
#endif //REVERSI_CLIENT_H