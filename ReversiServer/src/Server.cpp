/*
 * Server.cpp
 *
 *  Created on: Dec 4, 2017
 *      Author: omer
 */
#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#define MAX_CONNECTED_CLIENTS 10
using namespace std;

Server::Server(int port) :
		_port(port), _socket(0) {

}

Server::~Server() {
	// TODO Auto-generated destructor stub
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
		struct sockaddr_in clientAddress;
		socklen_t clientAddressLen;
		int client1Socket;
		int client2Socket;
		while (true) {
			cout << "Waiting for clients connections..." << endl;

			client1Socket = accept(_socket, (struct sockaddr *) &clientAddress,
					&clientAddressLen);
			cout << "Client 1 connected" << endl;
			if (client1Socket == -1) {
				throw "Error on accept";
			}

			cout << "Waiting for client 2 connection..." << endl;

			client2Socket = accept(_socket, (struct sockaddr *) &clientAddress,
					&clientAddressLen);
			cout << "Client 2 connected" << endl;
			if (client2Socket == -1) {
				throw "Error on accept";
			}

			int num_of_client = 1;
			write(client1Socket, &num_of_client, sizeof(num_of_client));
			num_of_client = 2;
			write(client2Socket, &num_of_client, sizeof(num_of_client));

			int i = 0;
			bool end_of_game=true;
			while (end_of_game) {
				if (i % 2 == 0) {
					end_of_game = handleClient(client1Socket, client2Socket);
				} else {
					end_of_game = handleClient(client2Socket, client1Socket);
				}
				i++;
			}
			close(client1Socket);
			close(client2Socket);
		}
}

bool Server::handleClient(int sender, int receiver) {
	char buffer_local[9];
	cout << "wait for receiving move " << sender << endl;

	int n = read(sender, buffer_local, 9);
	if (n == -1) {
		cout << "Error reading buffer_local" << endl;
		return buffer_local;
	}
	if (n == 0) {
		cout << "Client disconnected" << endl;
		return false;
	}
	cout << "Got move: " << buffer_local << endl;

	if(strcmp(buffer_local,"END")==0)
	{
		return false;
	}

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
 close(_socket);
}

