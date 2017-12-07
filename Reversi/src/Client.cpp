//
// Created by lee on 06/12/17.
//

#include "../include/Client.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

Client::Client(const char *serverIP, int serverPort) :
        serverIP(serverIP), serverPort(serverPort),
        clientSocket(0) {
    cout << "Client" << endl;
}

int Client::connectToServer() {
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        throw "Error opening socket";
    }
    struct in_addr address;
    if (!inet_aton(serverIP, &address)) {
        throw "Can't parse IP address";
    }
    struct hostent *server;
    server = gethostbyaddr((const void *) &address, sizeof
            address, AF_INET);
    if (server == NULL) {
        throw "Host is unreachable";
    }
    // Create a structure for the server address
    struct sockaddr_in serverAddress;
    bzero((char *) &address, sizeof(address));
    serverAddress.sin_family = AF_INET;
    memcpy((char *) &serverAddress.sin_addr.s_addr, (char
    *) server->h_addr, server->h_length);
    serverAddress.sin_port = htons(serverPort);
    if (connect(clientSocket, (struct sockaddr
    *) &serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error connecting to server";
    }
    cout << "Connected to server" << endl;

    int num_of_player;
    int n = read(clientSocket, &num_of_player, sizeof(num_of_player));
    if (n == -1) {
        throw "Error of reading from socket";
    }
    cout << "Your number is:" << num_of_player << endl;
    return num_of_player;
}

char *Client::receive() const {
    char *user_choice = new char[9];
    int n = read(clientSocket, user_choice, 9);
    if (n == -1) {
        throw "Error of reading from socket";
    }
    return user_choice;
}

void Client::send(char *user_choice) const {
    int n = write(clientSocket, user_choice, sizeof(user_choice));
    if (n == -1) {
        throw "Error of writing from socket";
    }
}

