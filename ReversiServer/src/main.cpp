
#include <iostream>
#include <fstream>
#include "../include/Server.h"

using namespace std;

int main() {
	// creating a server from file
	int port=0;
	ifstream inFile;
    try{
		inFile.open("config_server.txt");
		inFile >> port;
    }catch (const char *msg) {
        cout << "Cannot start server. Config Problem Reason: " << msg << endl;
    }
	Server server(port);
	// try to connect
	try {
		server.start();
	} catch (const char *msg) {
		cout << "Cannot start server. Reason: " << msg << endl;
	}
	// stop connection
	server.stop();
	return 0;
}
