
#include "../include/Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CONNECTED_CLIENTS 10
using namespace std;


Server::Server(int _port) : _port(_port), _socket(0) {
    server_container_ = new ServerContainer();
}

Server::~Server() {
    for (vector<pthread_t *>::iterator it = threads.begin(); it != threads.end(); ++it) {
        delete (*it);
    }
}

void Server::start() {
    // Create a socket point
    _socket = socket(AF_INET, SOCK_STREAM, 0);
    if (_socket == -1) {
        throw "Error opening socket";
    }
    // Assign a local address to the socket
    struct sockaddr_in serverAddress;
    bzero((void *) &serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(_port);
    if (bind(_socket, (struct sockaddr *) &serverAddress, sizeof(serverAddress))
        == -1) {
        throw "Error on binding";
    }
    listen(_socket, MAX_CONNECTED_CLIENTS);
    cout << "Waiting for clients connections..." << endl;
    int i = 0;
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen;
    while (true) {
        clientSocket = accept(_socket, (struct sockaddr *) &clientAddress,
                              &clientAddressLen);
        if (clientSocket == -1) {
            throw "Error on accept";
        }
        cout << "Client connected" << endl;
        addThread(clientSocket);
        i++;
    }
}


void Server::stop() {
    // close connection
    close(_socket);
}

void Server::addThread(int clientSocket) {
    pthread_t *newThread = new pthread_t();
    ClientHandler *c = new ClientHandler(clientSocket,server_container_);
    int rc = pthread_create(newThread, NULL, c->handleCommand, (void*)c);
    if (rc) {
        cout << "Error: unable to create thread, " << rc << endl;
        delete newThread;
        exit(-1);
    }
    threads.push_back(newThread);
    //pthread_exit(newThread);
}


int Server::getClientSocket() const {
    return clientSocket;
}

void Server::setClientSocket(int clientSocket) {
    Server::clientSocket = clientSocket;
}






