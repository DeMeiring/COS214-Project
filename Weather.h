#ifndef WEATHER_H
#define WEATHER_H

#include "Statistics.h"

class Weather_Selector {
private:
	Weather* weather_state = new Dry();
public:
	void setState(Weather*);
};

class Weather {

private:
	Statistics* stats;
	Weather* nextState;

public:
	Weather();
	Weather_Selector* ws;
	Statistics* getStats();
	void setStats(Statistics* stats);
	void setNextState(Weather* st);

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
