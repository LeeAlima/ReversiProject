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
}

void Client::sendMove(const char *user_choice) const {
    string copy;
    copy.append(user_choice);
    copy.append("\0");
    int n = send(client_socket_, copy.c_str(), copy.size()+1,0);
    if (n == -1) {
        throw "Error of writing to socket";
    }
}

char *Client::receive() const {
    char *user_choice = new char[100];
    // read from socket
    int n = read(client_socket_, user_choice, sizeof(user_choice));
    if (n == -1) {
        throw "Error of reading from socket";
    }
    return user_choice;
}
string Client::reciveMessage()const {
    char buffer[100]={0};
    string res="";
    int n;
    n=recv(client_socket_,buffer,99,0);
    if(n>0){
        res.append(buffer);
    } else{
        return "null";
    }
    return res;
}
int Client:: getClientSocket() const{
    return this->client_socket_;
}