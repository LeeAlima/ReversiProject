//
// Created by omer on 25/12/17.
//

#include <unistd.h>
#include "../include/ClientHandler.h"

struct ThreadArgs {
    ClientHandler *obj;
    int clientSocket;
};

ClientHandler::ClientHandler(int client_Socket) {
    RunServer run_server(client_Socket);
    comMan = new CommandManager(run_server);
}

bool ClientHandler::handleCommand(int clientSocket) {
    char buffer_local[9];
    string message = "";
    pair<string, vector<string>> cmd;
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
    comMan->executeCommand(cmd.first, cmd.second);
    //close(clientSocket);
}

pair<string, vector<string>> ClientHandler::extractCommand(string msg) {
    vector<string> args;
    string cmd = "";
    size_t prev = 0, pos = 0;
    pos = msg.find(" ", prev);
    if (pos == string::npos)
        return make_pair(msg, args);
    string token = msg.substr(prev, pos - prev);
    if (!token.empty())
        cmd.append(token);
    prev = pos + 1;
    do {
        // split by
        pos = msg.find(" ", prev);
        if (pos == string::npos)
            return make_pair(msg, args);
        token = msg.substr(prev, pos - prev);
        if (!token.empty())
            args.push_back(token);
        prev = pos + 1;
    } while (pos < msg.length() && prev < msg.length());

    return make_pair(cmd, args);
}


