//
// Created by lee on 21/12/17.
//

#include "../include/StartCommand.h"
#include "../include/RunServer.h"

StartCommand::StartCommand(RunServer *_run) : _run(_run) {}

StartCommand::~StartCommand() {

}

void StartCommand::execute(vector<string> args) {
    _run->startNewGame(args);
}
