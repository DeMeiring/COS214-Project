#ifndef CONC_RADIO_SYSTEM_H
#define CONC_RADIO_SYSTEM_H

#include "Radio_System.h"
#include <vector>

class Conc_Radio_System : public Radio_System {

public:

	virtual ~Conc_Radio_System();

	vector<Race_Crew*> RaceTeam;

	void addGroup(Race_Crew* group);

	virtual void PushCommand(Race_Crew* RaceMember, Command* command);

};

#endif
