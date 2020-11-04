#ifndef COMMAND_H
#define COMMAND_H

#include "Radio_System.h"
#include <string>

class Race_Crew;

using namespace std;
class Command {

private:
	Radio_System* Comms;
	string command_name;

public:
	void setReceiver(Radio_System* rec);
	void ForwardCommand(Race_Crew* RaceMember, string command);
};

#endif
