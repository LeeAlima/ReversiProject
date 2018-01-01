
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
     *  this method handle the exit command in server, it sends all of
     * the user the data about closing the server and print a message in the
     * server itself.
     */
    void stop();


private:
    int port;
    int server_socket_;
    pthread_t p_exit;
    pthread_mutex_t cout_mutex_;
};

#endif /* SRC_SERVER_H_ */
