#ifndef RACE_CREW_H
#define RACE_CREW_H

class Race_Crew {


public:
	void ReceiveCommand(Command* command);

	void SendCommand(Race_Crew* RaceMember, Command* command);
};

#endif
