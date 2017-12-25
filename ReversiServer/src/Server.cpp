
#include "../include/Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CONNECTED_CLIENTS 10
using namespace std;



Server::Server(int port) : _port(port), _socket(0) {
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
        cout << "Client connected" << endl;
        if (clientSocket == -1) {
            throw "Error on accept";
        }
        addThread(i);
        i++;
    }
}


bool Server::handleClient(int sender, int receiver) {
    char buffer_local[9];
    cout << "wait for receiving move " << sender << endl;
    int n = read(sender, buffer_local, 9);
    if (n == -1) {
        cout << "Error reading buffer_local" << endl;
        return false;
    }
    if (n == 0) {
        cout << "Client disconnected" << endl;
        return false;
    }
    cout << "Got move: " << buffer_local << endl;
    if (strcmp(buffer_local, "END") == 0) {
        return false;
    }
    // write data
    n = write(receiver, buffer_local, 9);
    if (n == -1) {
        cout << "Error writing buffer_local" << endl;
        return false;
    }
    if (n == 0) {
        cout << "Client disconnected" << endl;
        return false;
    }
    cout << "Sent Move:" << buffer_local << endl;
    return true;
}

void Server::stop() {
    // close connection
    close(_socket);
}

void Server::addThread(int i) {
    pthread_t *newThread = new pthread_t();
    threads.push_back(newThread);
    int rc = pthread_create(threads[i], NULL, connectClient, (void*)this);
    if (rc) {
        cout << "Error: unable to create thread, " << rc << endl;
        exit(-1);
    }
}

void *Server::connectClient(void *obj) {
    Server *ptr = (Server *)obj;
    ptr->_client_handler = new ClientHandler(ptr->clientSocket);
}



