/*
 * Server.h
 *
 *  Created on: Dec 4, 2017
 *      Author: omer
 */

#ifndef SRC_SERVER_H_
#define SRC_SERVER_H_
#include "Server.h"
#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;


class Server {
public:
	Server(int port);
	virtual ~Server();

	void start();

	void stop();
private:
	int _port;
	int _socket;
	bool handleClient(int sender, int receiver);

};

#endif /* SRC_SERVER_H_ */
