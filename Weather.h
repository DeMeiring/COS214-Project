#ifndef WEATHER_H
#define WEATHER_H

#include "Statistics.h"

class Weather {

private:
	Statistics* stats;
	Weather* nextState;

public:
	Weather();

	Statistics* getStats();
	void setStats(Statistics* stats);
	void setNextState(Weather* st);
	Weather* nextState();

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
