#include "Bahrain.h"
// medium
Bahrain::Bahrain() : Track(55) {
}

Bahrain::~Bahrain() {

}

string Bahrain::getName() {
    return "Bahrain";
}

string Bahrain::getCornerTypes() {
    return "Hair-pins with long straights";
}

Statistics* Bahrain::getBuffs() {
    Statistics *newStats = new Statistics(false, false, false, true);
    newStats->addStat("speed", 4);
    newStats->addStat("acceleration", 3);
    newStats->ChangeValue("racing_ability", 2);
    newStats->ChangeValue("handling", 1);
    return newStats;
}

Statistics* Bahrain::getDebuffs() {
    Statistics *newStats = new Statistics(false, false, false, true);
    newStats->ChangeValue("handling", 5);
    newStats->ChangeValue("failure", 3);
    return newStats;
}

string Bahrain::getFunFact() {
    return "Bahrain is only the third F1 race track to have taken place at night";
}