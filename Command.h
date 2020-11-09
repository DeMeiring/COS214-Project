#ifndef COMMAND_H
#define COMMAND_H

//#include "Radio_System.h"
#include <string>

class Race_Crew;
class Radio_System;

using namespace std;
class Command {

private:
	Radio_System* Comms; // mediator
	string command_name; // command to fulfil
	Race_Crew* invoker; // who invoked it for mediator

public:
	Command(string command, Radio_System* receiver, Race_Crew* rc);
	Radio_System* getRec();
	Race_Crew* getInvoker();
	string getCommand();
	virtual void ForwardCommand()=0;


	virtual ~Command(); // this may break stuff
};

#endif
