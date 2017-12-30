
#include "../include/Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CONNECTED_CLIENTS 10
using namespace std;


Server::Server(int _port) : _port(_port), _socket(0) {
    server_container_ = new ServerContainer();
    exit_from_server= false;
    pthread_mutex_init(&coutMutex, NULL);
    pthread_mutex_init(&serverExitMutex, NULL);
}

Server::~Server() {
    for (vector<pthread_t *>::iterator it = threads.begin(); it != threads.end(); ++it) {
        delete (*it);
    }
    delete server_container_;
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
    pthread_t pExit;
    int exitThreadResult = pthread_create(&pExit, NULL, exitThread, (void *) this);
    if (exitThreadResult) {
        cout << "Exit thread creation failed, exiting" << endl;
        return;
    } else {
        cout << "Enter 'exit' to close the server" << endl;
    }
    cout << "Waiting for clients connections..." << endl;
    int i = 0;
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen;
    while (!isExit_from_server()) {
        clientSocket = accept(_socket, (struct sockaddr *) &clientAddress,
                              &clientAddressLen);
        if (clientSocket == -1) {
            throw "Error on accept";
        }
        if (isExit_from_server()) {
            close(clientSocket);
            break;
        }
        cout << "Client connected" << endl;
        clientConnected[i]=clientSocket;
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

void *Server::exitThread(void *obj) {
    Server *server = (Server *) obj;
    string input;
    cin >> input;
    while (input != "exit") {
        cin >> input;
    }
    server->setExit_from_server(true);
    pthread_mutex_lock(&server->coutMutex);
    cout << "All done. All communications are closed!" << endl;
    pthread_mutex_unlock(&server->coutMutex);
    exit(-1);
}

bool Server::isExit_from_server() const {
    return exit_from_server;
}

void Server::setExit_from_server(bool exit_from_server) {
    Server::exit_from_server = exit_from_server;
}






