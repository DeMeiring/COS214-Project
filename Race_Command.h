#ifndef RACE_COMMAND_H
#define RACE_COMMAND_H

#include "Command.h"

class Race_Command : public Command {
public:
    Race_Command(Radio_System* rec, Race_Crew* invoker, string command);
    virtual void ForwardCommand();
    virtual ~Race_Command();
};

#endif
