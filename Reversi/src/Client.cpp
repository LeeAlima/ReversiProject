
#include "../include/Client.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

Client::Client(const char *serverIP, int serverPort) :
        server_IP_(serverIP), server_port_(serverPort),
        client_socket_(0) {
}

int Client::connectToServer() {
    client_socket_ = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket_ == -1) {
        throw "Error opening socket";
    }
    struct in_addr address;
    if (!inet_aton(server_IP_, &address)) {
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
    memcpy((char *) &serverAddress.sin_addr.s_addr,
           (char *) server->h_addr, server->h_length);
    serverAddress.sin_port = htons(server_port_);
    if (connect(client_socket_, (struct sockaddr
    *) &serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error connecting to server";
    }
    cout << "Connected to server" << endl;
    int num_of_player;
    int n = read(client_socket_, &num_of_player, sizeof(num_of_player));
    if (n == -1) {
        throw "Error of reading from socket";
    }
    cout << "Your number is:" << num_of_player << endl;
    return num_of_player;
}

void Client::send(char *user_choice) const {
    // write the user choice
    int n = write(client_socket_, user_choice, sizeof(user_choice));
    if (n == -1) {
        throw "Error of writing to socket";
    }
}

char *Client::receive() const {
    char *user_choice = new char[9];
    // read from socket
    int n = read(client_socket_, user_choice, 9);
    if (n == -1) {
        throw "Error of reading from socket";
    }
    return user_choice;
}