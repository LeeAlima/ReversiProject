//
// Created by omer on 25/12/17.
//

#include <unistd.h>
#include <sys/socket.h>
#include "../include/ClientHandler.h"


ClientHandler::ClientHandler(int client_Socket) : client_Socket(client_Socket) {
    list_of_games= new vector<Game*>;
    runServer= new RunServer(client_Socket,list_of_games);
    comMan = new CommandManager(runServer);
}

void* ClientHandler::handleCommand(void* obj) {
    ClientHandler *ptr = (ClientHandler *)obj;
    char buffer_local[20];
    string message = "";
    pair<string, vector<string>> cmd;
    cout << "wait for command " << ptr->client_Socket << endl;
    //int n = read(ptr->client_Socket, buffer_local, 20);
    int n = recv(ptr->client_Socket,buffer_local,19,0);
    if (n == -1) {
        cout << "Error reading buffer_local" << endl;
        return (void*)false;
    }
    if (n == 0) {
        cout << "Client disconnected" << endl;
        return (void*)false;
    }
    message.append(buffer_local);
    cmd = ptr->extractCommand(message);
    ptr->comMan->executeCommand(cmd.first, cmd.second);
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

        if (pos == string::npos) {
            pos = msg.length();
        }
        string token = msg.substr(prev, pos - prev);
        if (!token.empty()) {
            args.push_back(token);
        }
        prev = pos + 1;
    }while (pos < msg.length() && prev < msg.length());
    return make_pair(cmd,args);
}

void ClientHandler::setClient_Socket(int client_Socket) {
    ClientHandler::client_Socket = client_Socket;
    runServer->setClientSocket(client_Socket);
}




