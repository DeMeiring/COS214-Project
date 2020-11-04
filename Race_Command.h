#ifndef RACE_COMMAND_H
#define RACE_COMMAND_H

#include "Command.h"

class Race_Command : Command {
public:
    Race_Command(Radio_System* rec, Race_Crew* invoker, string command) : Command(command, rec, invoker) {};
    virtual void ForwardCommand();
};

#endif
