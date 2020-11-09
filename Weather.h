#ifndef WEATHER_H
#define WEATHER_H

#include "Statistics.h"

class Weather;

class Weather_Selector {
private:
	Weather* weather_state;
public:
    Weather_Selector();
	void setState(Weather*);
	void nextState();
	Weather* getState();
};

class Weather {

private:
	Statistics* stats;
	Weather* nextstate;
    Weather_Selector* ws;
    string weather;

public:
	Weather();
	Statistics* getStats();
	void setStats(Statistics* stats);
	void setNextState(Weather* st);
	void next_state();

	string getName();
	void setName(string set);

	virtual ~Weather(); 

};

class Dry : public Weather {
public:
	Dry();
	virtual ~Dry();
};

class Wet : public Weather {
public:
	Wet();
	virtual ~Wet();
};

class Raining : public Weather {
public:
	Raining();
	virtual ~Raining();
};

#endif
