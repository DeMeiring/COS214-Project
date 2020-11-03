#ifndef WEATHER_H
#define WEATHER_H

class Weather {

private:
	statistics stats;

public:
	Weather(statistics* stats);

	statistics* getStats();
};

#endif
