
#include "../include/JoinCommand.h"

JoinCommand::JoinCommand(RunServer *_run) : run(_run) { }

JoinCommand::~JoinCommand() { }

void JoinCommand::execute(vector<string> args) {
    run->joinToGame(args);
}