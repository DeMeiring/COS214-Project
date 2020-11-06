#include "Monaco.h"
// monaco
Monaco::Monaco() : Track(50) {

}

Monaco::~Monaco() {

}

string Monaco::getName() {
    return "Monaco Grand-Prix";
}

string Monaco::getCornerTypes() {
    return "Multiple chicanes, be careful at high speeds";
}

Statistics* Monaco::getBuffs() {
    Statistics *newStats = new Statistics(false, false, false, true);
    newStats->addStat("speed", 2);
    newStats->addStat("acceleration", 2);
    newStats->ChangeValue("racing_ability", 1);
    newStats->ChangeValue("handling", 4);
    return newStats;
}

Statistics* Monaco::getDebuffs() {
    Statistics *newStats = new Statistics(false, false, false, true);
    newStats->ChangeValue("handling", 10);
    newStats->ChangeValue("failure", 8);
    return newStats;
}

string Monaco::getFunFact() {
    "The circuit boasts the slowest corner in F1; turn six";
}