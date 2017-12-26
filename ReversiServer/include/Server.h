
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

    /**
     * this is the constructor of Server
     * @param port - the number of port
     */
    Server(int port);

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
	static void* connectClient(void* obj);
private:
	int _port;
	int _socket;
    ClientHandler *_client_handler;
    vector<pthread_t*> threads;
	int clientSocket;

    /**
     * this method handle the client by trying to read from the socket
     * and end game if needed
     * @param sender - number of sender
     * @param receiver - number of receiver
     * @return false if there was a problem of disconnection) and true
     * if the game can continue
     */
	bool handleClient(int sender, int receiver);

	void addThread(int i);
};

#endif /* SRC_SERVER_H_ */
