
#include "../include/Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_CONNECTED_CLIENTS 10
using namespace std;

/**
 * This method creates a new ClientHandler with the clientSocket number
 * and handle its commands in a thread.
 * It also adds the thread to the list of threads.
 * @param obj - Server object in cast from void*
 * @return null for error in sending the message
 */
static void *exitThread(void *obj);


Server::Server(int _port) : port(_port), server_socket_(0) {
}

Server::~Server() {
}

void Server::start() {
    // Create a socket point
    server_socket_ = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_ == -1) {
        throw "Error opening socket";
    }
    // Assign a local address to the socket
    struct sockaddr_in serverAddress;
    bzero((void *) &serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    if (bind(server_socket_, (struct sockaddr *) &serverAddress,
             sizeof(serverAddress)) == -1) {
        throw "Error on binding";
    }
    listen(server_socket_, MAX_CONNECTED_CLIENTS);
    int exit_thread_result = pthread_create(&p_exit, NULL, exitThread, (void *) server_socket_);
    if (exit_thread_result) {
        cout << "Exit thread creation failed, exiting" << endl;
        return;
    }
}


void Server::stop() {
    // close connection and exit program
    // save all of the client sockets to be able to make them
    // know the server is going to shut down.
    vector<int> sockets = ServerContainer::getInstance()->getClient_sockets();
    string msg = "-1";
    // inform all client
    for (int i = 0; i < sockets.size(); i++) {
        if (sockets[i] != NULL) {
            int n = send(sockets[i], msg.c_str(), msg.length(), 0);
            if (n == -1) { // error
                cout << "Error writing buffer_local" << endl;
                exit(0);
            }
        }
    }
    pthread_mutex_lock(&cout_mutex_);
    cout << "All done. All communications are closed!" << endl;
    pthread_mutex_unlock(&cout_mutex_);
    // close server and exit
    close(server_socket_);
    exit(0);
}

void *exitThread(void *server_socket_) {
    long serverSocket = (long) server_socket_;
    cout << "Waiting for clients connections..." << endl;
    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);
    // as long as the server should be activated
    while (true) {
        // accept client requests to connect the server
        int client_socket_ = accept(serverSocket, (struct sockaddr *) &client_address,
                                    &client_address_len);
        if (client_socket_ == -1) {
            throw "Error on accept";
        }
        cout << "Client connected" << endl;
        // add the client socket to the list of clients socket in ServerContainer
        ServerContainer::getInstance()->addClientSocket(client_socket_);
        // add thread to this client
        pthread_t threadId;
        int rc = pthread_create(&threadId, NULL, ClientHandler::handleCommand,
                                (void *) client_socket_);
        if (rc) {
            cout << "Error: unable to create thread, " << rc << endl;
        }
    }
}