#ifndef RACEDAY_STRAT_H
#define RACEDAY_STRAT_H

#include "Statistics.h"

class Driver;
class RaceDay_Strat {

private:
	Statistics* skill_modifier;

public:
    RaceDay_Strat(Statistics* stats);
	Statistics* getSkill_Modifier();
	virtual ~RaceDay_Strat()
};

#endif
