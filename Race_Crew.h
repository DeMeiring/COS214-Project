#ifndef RACE_CREW_H
#define RACE_CREW_H

#include "Race_Command.h"

class Radio_System;

class Race_Crew {

private:

	Radio_System* rs;

public:
	Race_Crew(Radio_System* rs);

	void ReceiveCommand(Command* command);

	void SendCommand(int i);

	void showAvailableCommands();
};

#endif
