#ifndef CONC_RADIO_SYSTEM_H
#define CONC_RADIO_SYSTEM_H

class Conc_Radio_System : Radio_System {

public:
	vector<RaceCrew*> RaceTeam;

	void addGroup(Race_Crew* group);
};

#endif
