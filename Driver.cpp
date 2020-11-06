#include "Driver.h"

Driver::Driver(Conc_Radio_System *rs, Statistics *stats, Skill_Level *skillLevel, Prepared *preparedness,
               RaceDay_Strat *raceDayStrat, Statistics *overstat,std::string name,int contractCost) : Race_Crew(rs) {
    this->stats=stats;
    this->skill_level=skillLevel;
    this->preparedness=preparedness;
    this->RaceDayStrat = raceDayStrat;
    this->overStat = overstat;
    this->name= name;
    this->ContractCost=ContractCost;
}

Statistics* Driver::getStats() {
	return this->stats;
}

void Driver::setStats(Statistics* stats) {
	this->stats = stats;
}

Statistics* Driver::Stats_Modifier() {
	// TODO - implement Driver::Stats_Modifier
	throw "Not yet implemented";
}

int Driver::getContractCost() {
	// TODO - implement Driver::getContractCost
	throw "Not yet implemented";
}

Driver::~Driver() {
	
}

std::string Driver::getName() {
    return this->name;
}
