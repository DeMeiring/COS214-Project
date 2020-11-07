#include "Driver.h"
#include "Statistics.h"

Driver::Driver(Conc_Radio_System *rs, Statistics *stats,std::string name,int contractCost) : Race_Crew(rs) {
    this->stats=stats;
    this->preparedness=preparedness;
    this->name= name;
    this->ContractCost=contractCost;
}

Statistics* Driver::getStats() {
	return this->stats;
}

void Driver::setStats(Statistics* stats) {
	this->stats = stats;
}

Statistics* Driver::Stats_Modifier() {
}

int Driver::getContractCost() {
	return this->ContractCost;
}

Driver::~Driver() {
	
}

std::string Driver::getName() {
    return this->name;
}

void Driver::initRaceDay() {
    this->RaceDayStrat = RaceDayStrat;
    std::string name = this->name;
    if(name=="Liam"){


    }else if(name=="Matthew"){

    }else if(name=="DeVilliers"){

    }else if(name=="Dean"){

    }else if(name=="Joseph"){

    }
}

void Driver::initSkillLevel() {

}

void Driver::initPrepared() {

}

void Driver::setOverallStats(Statistics* overStat) {
    this->overStat = overStat;
}

void Driver::setRaceDay(RaceDay_Strat *raceDayStrat) {
    this->RaceDayStrat = raceDayStrat;
}

void Driver::setSkillLevel(Skill_Level *skillLevel) {
    this->skill_level=skillLevel;
}

void Driver::setPrepared(Prepared *prepared) {
    this->preparedness=prepared;
}
