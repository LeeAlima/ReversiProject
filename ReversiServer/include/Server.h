
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

using namespace std;


class Server {
public:

    Server(int _port);

    /**
     * this is the destructor of Server
     */
	virtual ~Server();

    /**
     * start connection
     */
	void start();


    int getClientSocket() const;

    void setClientSocket(int clientSocket);

    /**
     * stop connection
     */
	void stop();
private:
	int _port;
	int _socket;
    vector<pthread_t*> threads;
	int clientSocket;
    ClientHandler *c;

	void addThread(int clientSocket);
};

#endif /* SRC_SERVER_H_ */
