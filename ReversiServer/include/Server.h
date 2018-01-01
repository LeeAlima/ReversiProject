
#ifndef SRC_SERVER_H_
#define SRC_SERVER_H_

#include "Server.h"
#include "Game.h"
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <list>
#include <vector>
#include "CommandManager.h"
#include "ClientHandler.h"
#include "ServerContainer.h"

using namespace std;

class Server {
public:
    /**
     * constructor for Server
     * @param _port - as the port number of the server
     */
    Server(int _port);

    /**
     * this is the destructor of Server
     */
    virtual ~Server();

    /**
     * start connection
     */
    void start();

    /**
     * this method handle the exit command in server, it sends all of
     * the user the data about closing the server and print a message in the
     * server itself.
     * @param obj - Server object in cast from void*
     * @return null for error in sending the message
     */
    static void *exitThread(void *obj);

    /**
     * this method stops the connection and exit the server.
     */
    void stop();

    /**
     * this method informs if there is a need in closing the socket.
     * @return true if there is a need and false otherwise.
     */
    bool isExitFromServer() const;

    /**
     * this method set the exit_from_server boolean
     * @param exit_from_server - bool
     */
    void setExitFromServer(bool exit_from_server);


private:
    int port;
    int server_socket_;
    int client_socket_;
    int clientConnected[10];
    vector<pthread_t *> threads;
    ServerContainer *server_container_;
    bool exit_from_server;
    pthread_mutex_t server_exit_mutex_;
    pthread_mutex_t cout_mutex_;

    /**
     * This method creates a new ClientHandler with the clientSocket number
     * and handle its commands in a thread.
     * It also adds the thread to the list of threads.
     * @param clientSocket - the number of client socket.
     */
    void addThread(int clientSocket);
};

#endif /* SRC_SERVER_H_ */
