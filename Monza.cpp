#include "Monza.h"
// easy
Monza::Monza() : Track(45) {

}
    
Monza::~Monza() {

}

string Monza::getName() {
    return "Italian Grand-Prix";
}

string Monza::getCornerTypes() {
    return "Multiple apexes with fast cornering a must";
}

Statistics* Monza::getBuffs() {
    Statistics *newStats = new Statistics(false, false, false, true);
    addStat("speed", 8);
    addStat("acceleration", 5);
    newStats->ChangeValue("racing_ability", 5);
    newStats->ChangeValue("handling", 5);
    setStats(newStats);
}

Statistics* Monza::getDebuffs() {
    Statistics *newStats = new Statistics(false, false, false, true);
    newStats->ChangeValue("handling", 2);
    newStats->ChangeValue("failure", 1);
    setStats(newStats);
}

string Monza::getFunFact() {
    return "Monza is the fastest track on the F1 calendar with drivers reaching speeds of 350km/h";
}