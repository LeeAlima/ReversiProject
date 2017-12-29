
#include "../include/ListCommand.h"

ListCommand::ListCommand(RunServer *_run) : run(_run) {}

ListCommand::~ListCommand() { }

void ListCommand::execute(vector <string> args) {
    run->listOfGames(args);
}