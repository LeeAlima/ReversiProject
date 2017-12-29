
#include "../include/CloseCommand.h"

CloseCommand::CloseCommand(RunServer *run) : run(run) { }

CloseCommand::~CloseCommand() { }

void CloseCommand::execute(vector<string> args) {
    run->closeGame(args);
}