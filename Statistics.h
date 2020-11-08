#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>
#include <string>

class Engineering;

using namespace std;

struct single_stat {
	int stat;
	string name;
};

class Statistics {

private:
	vector<single_stat*> values;

    // base driver stats before modifying for presets
    void init_driver_stats();

    // for base car before any components or upgrades, also creates component's stats variable
    void init_car_stats(bool isComp,bool isCar=false);

    // for weather in race_day
    void init_weather();

public:

    void addStat(string name, int value);

	// set true the boolean which you are writing stats for
	// a proper implementation would be each boolean as a class which inherits
	Statistics(bool isCar=false, bool isDriver=false, bool isComp=false, bool isOther=false);

	// this class can do the searching for the correct stat and so
	// on to make code more organized

	// find is the name of the ability, look in the cpp for the names <3
	// change the value, append = false CHANGES THE VALUE, append = true
	// ADDS TO THE VALUE if inc = true
	bool ChangeValue(string find, int value, bool append=false, bool inc=true);

	int getValue(string find);

	vector<int> getAllValues();
};

#endif
