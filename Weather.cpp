#include "Weather.h"

void Weather_Selector::nextState() {
    weather_state->next_state();
}

void Weather::next_state() {
    ws->setState(nextstate);
}


Weather_Selector::Weather_Selector() {
    weather_state = new Dry();
}

Statistics* Weather::getStats() {
	return stats;
}

void Weather_Selector::setState(Weather* set) {
    weather_state = set;
}

void Weather::setStats(Statistics* stats) {
    this->stats = stats;
}

void Weather::setNextState(Weather* st) {
    nextstate = st;
}

Weather* Weather_Selector::getState() {
    return weather_state;
}


Dry::Dry() {
    setName("dry");
	setNextState(new Wet());
	Statistics *newStats = new Statistics(false, false, false, true);
	//newStats->ChangeValue("weather_debuff", 0);
	newStats->ChangeValue("racing_ability", 0);
    newStats->ChangeValue("handling", 0);
    newStats->ChangeValue("failure", 0);
    setStats(newStats);
}

Wet::Wet() {
    setName("wet");
	setNextState(new Raining());
    Statistics *newStats = new Statistics(false, false, false, true);
    //newStats->ChangeValue("weather_debuff", 20);
    newStats->ChangeValue("racing_ability", 10);
    newStats->ChangeValue("handling", 15);
    newStats->ChangeValue("failure", 18);
    setStats(newStats);
}

Raining::Raining() {
    setName("raining");
	setNextState(new Dry());
    Statistics *newStats = new Statistics(false, false, false, true);
    newStats->ChangeValue("weather_debuff", 30);
    newStats->ChangeValue("racing_ability", 15);
    newStats->ChangeValue("handling", 20);
    newStats->ChangeValue("failure", 25);
    setStats(newStats);
}

string Weather::getName() {
    return weather;
}
void Weather::setName(string set) {
    weather = set;
}


