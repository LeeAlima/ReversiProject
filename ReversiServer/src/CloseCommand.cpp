//
// Created by lee on 21/12/17.
//

#include "../include/CloseCommand.h"
#include "../include/RunServer.h"

CloseCommand::CloseCommand(RunServer *_run) : _run(_run) {}

CloseCommand::~CloseCommand() {

}

void CloseCommand::execute(vector<string> args) {
    _run->closeGame(args);
}
