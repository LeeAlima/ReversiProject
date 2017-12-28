
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
     * this method connect to the server and return the number of the player
     * @return int - as the number of the player (1/2)
     */
    int connectToServer();

    /**
     * this method sends message to the server
     * @param msg - the message the user wants to deliver the server
     */
    void sendMessage(const char *msg) const;

    /**
     * this method receive a point from the socket and returns it
     * @return char* - the point
     */
    char* receive() const;

    /**
     * this method returns the client socket
     * @return int - client socket
     */
    int getClientSocket() const;

    /**
     * this method receives message from the server
     * @return string - the message
     */
    string reciveMessage() const;

    /**
     * this method sends the server a point(move)
     * @param user_choice - the move the user chose
     */
    void sendMove(char *user_choice) const;

private:
    const char *server_IP_;
    int server_port_;
    int client_socket_;

};
#endif //REVERSI_CLIENT_H