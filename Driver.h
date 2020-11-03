#ifndef DRIVER_H
#define DRIVER_H

class Driver : Race_Crew {

private:
	Statistics* stats;
	Skill_Level* skill_level;
	Prepared* preparedness;
	RaceDay_Strat* RaceDayStrat;
	Statistics* overStat;
	int ContractCost;

public:
	Statistics* getStats();

	void setStats(Statistics* stats);

	Statistics* Stats_Modifier();

	int getContractCost();
};

#endif
