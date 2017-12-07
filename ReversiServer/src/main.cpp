/*
 * main.cpp
 *
 *  Created on: Dec 4, 2017
 *      Author: omer
 */

#include <iostream>
#include "Server.h"
#include <stdlib.h>

using namespace std;

int main() {
	   Server server(1234);
	    try {
	        server.start();
	    } catch (const char *msg) {
	        cout << "Cannot start server. Reason: " << msg << endl;
	        }
	    server.stop();
	     return 0;
}
