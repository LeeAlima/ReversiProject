
#include "../include/Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_CONNECTED_CLIENTS 10
using namespace std;


Server::Server(int _port) : port(_port), server_socket_(0) {
    server_container_ = new ServerContainer();
    exit_from_server = false;
    pthread_mutex_init(&cout_mutex_, NULL);
    pthread_mutex_init(&server_exit_mutex_, NULL);
}

Server::~Server() {
    for (vector<pthread_t *>::iterator it = threads.begin();
         it != threads.end(); ++it) {
        delete (*it);
    }
    delete server_container_;
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
    pthread_t p_exit;
    int exit_thread_result = pthread_create(&p_exit, NULL, exitThread, (void *) this);
    if (exit_thread_result) {
        cout << "Exit thread creation failed, exiting" << endl;
        return;
    } else {
        cout << "Enter 'exit' to close the server" << endl;
    }
    cout << "Waiting for clients connections..." << endl;
    struct sockaddr_in client_address;
    socklen_t client_address_len;
    // as long as the server should be activated
    while (!isExitFromServer()) {
        // accept client requests to connect the server
        client_socket_ = accept(server_socket_, (struct sockaddr *) &client_address,
                              &client_address_len);
        if (client_socket_ == -1) {
            throw "Error on accept";
        }
        if (isExitFromServer()) {
            close(client_socket_);
            break;
        }
        cout << "Client connected" << endl;
        // add the client socket to the list of clients socket in ServerContainer
        server_container_->addClientSocket(client_socket_);
        // add thread to this client
        addThread(client_socket_);
    }
}


void Server::stop() {
    // close connection and exit program
    close(server_socket_);
    exit(0);
}

void Server::addThread(int clientSocket) {
    // create a new thread
    pthread_t *newThread = new pthread_t();
    // create a client handler object with the client socket and the server container
    ClientHandler *client_handler = new ClientHandler(clientSocket, server_container_);
    // handle commands
    int rc = pthread_create(newThread, NULL, client_handler->handleCommand,
                            (void *) client_handler);
    if (rc) {
        cout << "Error: unable to create thread, " << rc << endl;
        delete newThread;
    }
    // add the thread to the list of threads
    threads.push_back(newThread);
}

void *Server::exitThread(void *obj) {
    Server *server = (Server *) obj;
    // cin input
    string input;
    cin >> input;
    // scan input until user ask for exit
    while (input != "exit") {
        cin >> input;
    }
    // save all of the clients sockets
    vector<int> sockets = server->server_container_->getClient_sockets();
    // change the boolean member of exit server to true
    server->setExitFromServer(true);
    string msg = "-1";
    // go over the sockets number and send them a signal
    // that the server is going to shut down
    for (int i = 0; i < sockets.size(); i++) {
        if (sockets[i] != NULL) {
            int n = send(sockets[i], msg.c_str(), msg.length(), 0);
            if (n == -1) { // error
                cout << "Error writing buffer_local" << endl;
                return NULL;
            }
        }
    }
    pthread_mutex_lock(&server->cout_mutex_);
    cout << "All done. All communications are closed!" << endl;
    pthread_mutex_unlock(&server->cout_mutex_);
    // stop server
    server->stop();
}

bool Server::isExitFromServer() const {
    return exit_from_server;
}

void Server::setExitFromServer(bool exit_from_server) {
    Server::exit_from_server = exit_from_server;
}