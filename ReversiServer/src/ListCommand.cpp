
#include "../include/ListCommand.h"

ListCommand::ListCommand(RunServer *run) : run(run) {}

ListCommand::~ListCommand() {}

void ListCommand::execute(vector<string> args) {
    // call listOfGames in RunServer
    run->listOfGames(args);
}