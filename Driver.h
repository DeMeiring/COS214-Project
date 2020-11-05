#ifndef DRIVER_H
#define DRIVER_H

#include "Race_Crew.h"
#include "Skill_Level.h"
#include "Prepared.h"
#include "RaceDay_Strat.h"

class Driver : public Race_Crew {

private:
	Statistics* stats;
	Skill_Level* skill_level;
	Prepared* preparedness;
	RaceDay_Strat* RaceDayStrat;
	Statistics* overStat;
	int ContractCost;

public:
	Driver();

	Statistics* getStats();

	void setStats(Statistics* stats);

	Statistics* Stats_Modifier();

	int getContractCost();

	virtual ~Driver();
};

#endif
