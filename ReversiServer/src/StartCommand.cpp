
#include "../include/StartCommand.h"

StartCommand::StartCommand(RunServer *run) : run(run) {}

StartCommand::~StartCommand() {}

void StartCommand::execute(vector<string> args) {
    // call startNewGame in RunServer
    run->startNewGame(args);
}