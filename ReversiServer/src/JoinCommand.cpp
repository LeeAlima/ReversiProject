//
// Created by lee on 21/12/17.
//

#include "../include/JoinCommand.h"
#include "../include/RunServer.h"

JoinCommand::JoinCommand(RunServer *_run) : _run(_run) {}

JoinCommand::~JoinCommand() {

}

void JoinCommand::execute(vector<string> args) {
    _run->joinToGame(args);
}


