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
	A_Opposing_Team* OppTeamFact;
	vector<OpposingDriver*> OpposingDrivers;

public:

	Teams();

	vector<OpposingDriver*> GenDrivers();

	vector<OpposingDriver*> getOpposingDrivers();

	virtual ~Teams();

};

#endif
