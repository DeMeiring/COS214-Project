#ifndef RACE_CREW_H
#define RACE_CREW_H

#include "Race_Command.h"
#include <iostream>

class Radio_System;

class Race_Crew {

private:

	Radio_System* rs;

public:

    Race_Crew();

    virtual ~Race_Crew();

	Race_Crew(Radio_System* rs);

	virtual void ReceiveCommand(Command* command);

	virtual void SendCommand(Command* command);

	virtual void showAvailableCommands();

	Radio_System* getRS();

};

#endif
