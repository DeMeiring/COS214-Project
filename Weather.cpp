#include "Weather.h"

Statistics* Weather::getStats() {
	return stats;
}

Dry::Dry() {
	setNextState(new Wet());
	Statistics *newStats = new Statistics(false, false, false, true);
	newStats->ChangeValue("racing_ability", 0);
    newStats->ChangeValue("handling", -3);
    newStats->ChangeValue("failure", 0);
    setStats(newStats);
}

Wet::Wet() {
	setNextState(new Raining());
    Statistics *newStats = new Statistics(false, false, false, true);
    newStats->ChangeValue("racing_ability", -10);
    newStats->ChangeValue("handling", -15);
    newStats->ChangeValue("failure", -18);
    setStats(newStats);
}

Raining::Raining() {
	setNextState(new Dry());
    Statistics *newStats = new Statistics(false, false, false, true);
    newStats->ChangeValue("racing_ability", -15);
    newStats->ChangeValue("handling", -20);
    newStats->ChangeValue("failure", -25);
    setStats(newStats);
}
