#ifndef TEAMS_H
#define TEAMS_H

#include <vector>
#include <tuple>
#include "Driver.h"
#include "Engineering.h"
#include "Opposing_Team.h"

using namespace std;

class Teams {

private:
	vector<OpposingDriver*> OpposingDrivers;

public:

	Teams();

	vector<OpposingDriver*> GenDrivers

	Driver* getDriverbyName(string name);

	Driver* getDriver(int index);

	void printDriverList();

	virtual ~Teams();

};

#endif
