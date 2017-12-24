
#include "../include/Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_CONNECTED_CLIENTS 10
using namespace std;

struct ThreadArgs {
    Server* obj;
    int clientSocket;
};

Server::Server(int port) : _port(port), _socket(0){
    command_manger=new CommandManager();
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
	int clientSocket;
	int i=0;
    cout << "Waiting for clients connections..." << endl;
    while (true) {
		clientSocket = accept(_socket, (struct sockaddr *) &clientAddress,
							   &clientAddressLen);
		cout << "Client "<<i<<" connected" << endl;
		if (clientSocket == -1) {
			throw "Error on accept";
		}
		pthread_t p;
		threads.push_back(p);
        int rc = pthread_create(&threads[i],NULL,executeHandleCommand,&clientSocket);
		if (rc) {
			cout << "Error: unable to create thread, " << rc << endl;
			exit(-1);
		}
		i++;
	}
}

bool Server::handleClient(int sender, int receiver) {
	char buffer_local[9];
	cout << "wait for receiving move " << sender << endl;
	int n = read(sender, buffer_local, 9);
	if (n == -1) {
		cout << "Error reading buffer_local" << endl;
		return false;
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
	// write data
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
	// close connection
	close(_socket);
}

bool Server::handleCommand(int clientSocket) {
    char buffer_local[9];
    string message = "";
    pair<string, vector<string>> cmd;
    while (true){
        cout << "wait for command " << clientSocket << endl;
        int n = read(clientSocket, buffer_local, 9);
        if (n == -1) {
            cout << "Error reading buffer_local" << endl;
            return false;
        }
        if (n == 0) {
            cout << "Client disconnected" << endl;
            return false;
        }
        message.append(buffer_local);
        cmd = extractCommand(message);
        command_manger->executeCommand(cmd.first,cmd.second);
        close(clientSocket);
    }
}

pair<string, vector<string>> Server::extractCommand(string msg) {
    vector<string> args;
    string cmd="";
    size_t prev = 0, pos = 0;
    pos = msg.find(" ", prev);
    if (pos == string::npos)
        return make_pair(msg,args);
    string token = msg.substr(prev, pos - prev);
    if (!token.empty())
        cmd.append(token);
    prev = pos + 1;
    do {
        // split by
        pos = msg.find(" ", prev);
        if (pos == string::npos)
            return make_pair(msg,args);
        token = msg.substr(prev, pos - prev);
        if (!token.empty())
            args.push_back(token);
        prev = pos + 1;
    } while (pos < msg.length() && prev < msg.length());

    return make_pair(cmd,args);
}

void *Server::executeHandleCommand(void *tArgs) {
        struct ThreadArgs *args = (struct ThreadArgs *)tArgs;
        args->obj->handleCommand(args->clientSocket);
}


