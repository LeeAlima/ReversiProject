
#include "../include/CloseCommand.h"

CloseCommand::CloseCommand(RunServer *run) : run(run) {}

CloseCommand::~CloseCommand() {}

void CloseCommand::execute(vector<string> args) {
    // call closeGame in RunServer
    run->closeGame(args);
}