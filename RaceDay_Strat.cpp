#include "RaceDay_Strat.h"
#include "Driver.h"
#include "Statistics.h"

RaceDay_Strat::RaceDay_Strat(Statistics *stats) {
    this->skill_modifier=stats;
}

Statistics* RaceDay_Strat::getSkill_Modifier() {
	return this->skill_modifier;
}

RaceDay_Strat::~RaceDay_Strat() {
    delete this->skill_modifier;
}
