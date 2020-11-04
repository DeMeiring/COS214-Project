#ifndef TEAMS_H
#define TEAMS_H

#include <vector>
#include <tuple>
#include "Driver.h"
#include "Engineering.h"
#include "A_Opposing_Team.h"

using namespace std;

class Teams {

private:
	vector<tuple<string, string, Driver*, Engineering*>> OpposingDrivers;

public:

	Teams();

	Driver* getDriverbyName(string name);

	Driver* getDriver(int index);

	void printDriverList();

	virtual ~Teams();

};

#endif
