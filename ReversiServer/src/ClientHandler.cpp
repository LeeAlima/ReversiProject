
#include <unistd.h>
#include <sys/socket.h>
#include "../include/ClientHandler.h"

ClientHandler::ClientHandler(int client_Socket, ServerContainer *serverContainer)
        : client_Socket_(client_Socket), server_container_(serverContainer) {
    run_server_ = new RunServer(client_Socket, serverContainer);
    command_mannager_ = new CommandManager(run_server_);
}

ClientHandler::~ClientHandler() {
    delete run_server_;
    delete command_mannager_;
}

void *ClientHandler::handleCommand(void *obj) {
    // cast obj
    ClientHandler *ptr = (ClientHandler *) obj;
    // create a buffer at max size to save the message from the client in it
    char buffer_local[MaxSize];
    string message = "";
    pair<string, vector<string> > cmd;
    cout << "wait for command " << ptr->client_Socket_ << endl;
    // call recv and read the client message and save it at buffer local
    int n = recv(ptr->client_Socket_, buffer_local, MaxSize - 1, 0);
    if (n == -1) {
        cout << "Error reading buffer_local" << endl;
        return (void *) false;
    }
    if (n == 0) {
        cout << "Client disconnected" << endl;
        ptr->server_container_->removeClientSocket(ptr->client_Socket_);
        return (void *) false;
    }
    // append buffer_local to message
    message.append(buffer_local);
    // call extractCommant
    cmd = ptr->extractCommand(message);
    // execute command
    ptr->command_mannager_->executeCommand(cmd.first, cmd.second);
}

pair<string, vector<string> > ClientHandler::extractCommand(string msg) {
    vector<string> args;
    // split the message by a space
    string cmd = "";
    size_t prev = 0, pos = 0;
    pos = msg.find(" ", prev);
    if (pos == string::npos)
        // make pair and return it
        return make_pair(msg, args);
    // save command
    string command = msg.substr(prev, pos - prev);
    if (!command.empty()) // append the command to message
        cmd.append(command);
    string game_name = msg.substr(pos + 1, msg.size() );
    args.push_back(game_name);
    // return the pair
    return make_pair(cmd, args);
}