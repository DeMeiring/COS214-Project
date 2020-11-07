#ifndef DRIVER_H
#define DRIVER_H

#include "Race_Crew.h"
#include "Skill_Level.h"
#include "Prepared.h"
#include "RaceDay_Strat.h"
#include "Statistics.h"
#include "Conc_Radio_System.h"

class Driver : public Race_Crew {

private:
    std::string name;
	Statistics* stats;
	Skill_Level* skill_level;
	Prepared* preparedness;
	RaceDay_Strat* RaceDayStrat;
	Statistics* overStat;
	int ContractCost;

public:
	Driver(Conc_Radio_System *rs, Statistics *stats,std::string name,int ContractCost);

	Statistics* getStats();

	void setStats(Statistics* stats);

	Statistics* Stats_Modifier();

	int getContractCost();

	std::string getName();

	//setters for raceday,overstat,preparedness,skill_level

	void initRaceDay();

	void initSkillLevel();

	void initPrepared();


	void setRaceDay(RaceDay_Strat* raceDayStrat);

	void setSkillLevel(Skill_Level* skillLevel);

	void setPrepared(Prepared* prepared);

    void setOverallStats(Statistics* overStat);

	virtual ~Driver();
};

#endif
