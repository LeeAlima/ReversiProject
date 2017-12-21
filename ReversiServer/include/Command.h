//
// Created by lee on 21/12/17.
//

#ifndef REVERSISERVER_COMMAND_H
#define REVERSISERVER_COMMAND_H


#include <vector>
#include <string>
using namespace std;
class Command {
public:
    virtual void execute(vector<string> args) = 0;
    virtual ~Command() {}
};


#endif //REVERSISERVER_COMMAND_H