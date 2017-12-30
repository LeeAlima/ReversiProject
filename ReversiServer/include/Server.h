
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

	static void* exitThread(void* obj);

    /**
     * stop connection
     */
	void stop();
private:
	int _port;
public:
	bool isExit_from_server() const;

	void setExit_from_server(bool exit_from_server);

private:
	int _socket;
	int clientSocket;
	int clientConnected[10];
    vector<pthread_t*> threads;
	ServerContainer *server_container_;
	bool exit_from_server;
	void addThread(int clientSocket);
	pthread_mutex_t serverExitMutex;
	pthread_mutex_t coutMutex;
};

#endif /* SRC_SERVER_H_ */
