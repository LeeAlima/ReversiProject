//
// Created by lee on 21/12/17.
//


#include "../include/ListCommand.h"

ListCommand::ListCommand(RunServer &_run) : _run(_run) {}

ListCommand::~ListCommand() {}

void ListCommand::execute(vector <string> args) {
    _run.listOfGames(args);
}


