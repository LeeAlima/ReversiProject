
#include <iostream>
#include "Server.h"

using namespace std;

int main() {
	// creating a server
	Server server(1234);
	// try to connecct
	try {
		server.start();
	} catch (const char *msg) {
		cout << "Cannot start server. Reason: " << msg << endl;
	}
	// stop connection
	server.stop();
	return 0;
}