#ifndef RADIO_SYSTEM_H
#define RADIO_SYSTEM_H

#include "Race_Command.h"
#include "Race_Crew.h"

class Radio_System {

public:
	virtual void PushCommand(Race_Crew* RaceMember, Command* command)=0;
};

#endif
