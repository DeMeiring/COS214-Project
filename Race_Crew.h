#ifndef RACE_CREW_H
#define RACE_CREW_H

#include "Command.h"

class Race_Crew {

private:
	Command* rec;

protected:
	Command getCommand();
	void setCommand(Command* command);
public:
	void ReceiveCommand(Command* command);

	void SendCommand(Race_Crew* RaceMember, Command* command);
};

#endif
