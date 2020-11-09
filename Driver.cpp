#include "Driver.h"
#include "Statistics.h"

using namespace std;

Driver::Driver(Conc_Radio_System *rs, Statistics *stats,std::string name,int contractCost) : Race_Crew(rs) {
    this->stats = stats;
    this->preparedness = preparedness;
    this->name = name;
    this->ContractCost = contractCost;
}

Statistics* Driver::getStats() {
	return this->stats;
}

void Driver::setStats(Statistics* stats) {
	this->stats = stats;
}

Statistics* Driver::Stats_Modifier()
{
}

int Driver::getContractCost()
{
	return this->ContractCost;
}

Driver::~Driver()
{
    delete stats;
    delete skill_level;
    delete preparedness;
    delete RaceDayStrat;
    delete overStat;

    stats = nullptr;
    skill_level = nullptr;
    preparedness = nullptr;
    RaceDayStrat = nullptr;
    overStat = nullptr;
}

std::string Driver::getName()
{
    return this->name;
}

void Driver::initRaceDay()
{
    this->RaceDayStrat = RaceDayStrat;
    string name = this->name;

    if(name=="Liam")
    {
        this->RaceDayStrat = new Conservative(this->stats);
    }
    else if(name=="Matthew")
    {
        this->RaceDayStrat = new Risky(this->stats);
    }
    else if(name=="DeVilliers")
    {
        this->RaceDayStrat = new Risky(this->stats);
    }
    else if(name=="Dean")
    {
        this->RaceDayStrat = new Aggressive(this->stats);
    }else if(name=="Joseph")
    {
        this->RaceDayStrat = new Aggressive(this->stats);
    }
}

void Driver::initSkillLevel()
{
    string name = this->name;

    if(name=="Liam")
    {
        this->skill_level = new Pro(this->stats);
    }
    else if(name=="Matthew")
    {
        this->skill_level = new Rookie(this->stats);
    }
    else if(name=="DeVilliers")
    {
        this->skill_level = new Rookie(this->stats);
    }
    else if(name=="Dean")
    {
        this->skill_level = new Experienced(this->stats);
    }
    else if(name=="Joseph")
    {
        this->skill_level = new Experienced(this->stats);
    }
}

void Driver::initPrepared()
{
    string name = this->name;

    if(name=="Liam")
    {
        this->preparedness = new Unprepared(this->stats);
    }
    else if(name=="Matthew")
    {
        this->preparedness = new Moderate(this->stats);
    }
    else if(name=="DeVilliers")
    {
        this->preparedness = new Prepared(this->stats);
    }
    else if(name=="Dean")
    {
        this->preparedness = new Unprepared(this->stats);
    }
    else if(name=="Joseph")
    {
        this->preparedness = new Moderate(this->stats);
    }

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

// Apply the modifiers we have set

Statistics* Driver::applyChanges()
{
    // Initializes the stats before we set them 
    initPrepared();
    initRaceDay();
    initSkillLevel();

    // true true = add
    // true false = sub
    // false false = replace

    // Sets the stats using Statistics change value
    this->stats->ChangeValue("preparedness", this->preparedness->getPreparedness(), true, true);
    this->stats->ChangeValue("racing_ability", this->skill_level->getRacingAbility(), true, true);
    this->stats->ChangeValue("aggression",this->RaceDayStrat->getAggression(), true, true);
    this->stats->ChangeValue("conservative", this->RaceDayStrat->getConservative(), true, true);

    return this->stats;
}