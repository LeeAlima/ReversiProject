
#include "../include/JoinCommand.h"

JoinCommand::JoinCommand(RunServer *run) : run(run) {}

JoinCommand::~JoinCommand() {}

void JoinCommand::execute(vector<string> args) {
    // call joinToGame method in RunServer
    run->joinToGame(args);
}