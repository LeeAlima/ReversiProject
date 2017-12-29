
#ifndef REVERSISERVER_COMMAND_H
#define REVERSISERVER_COMMAND_H


#include <vector>
#include <string>
using namespace std;

/**
 * Interface of Command, we will create classed that implements this class
 * and use the command design pattern.
 */
class Command {
public:
    /**
     * this method execute the command using the vector of args.
     * this is a pute virtual method
     * @param args - vector of string
     */
    virtual void execute(vector<string> args) = 0;

    /**
     * destructor for command
     */
    virtual ~Command() {}
};


#endif //REVERSISERVER_COMMAND_H
