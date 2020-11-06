#ifndef A_OPPOSING_TEAM_H
#define A_OPPOSING_TEAM_H

#include <tuple>
#include <vector>
#include "Driver.h"
#include "Engineering.h"
#include "Tyres.h"

using namespace std;

// this struct may need to be moved
struct OpposingDriver {
		string team;
		string name;
		Driver* driver;
		Engineering* car;
		Tyres* tyre;
	};

class A_Opposing_Team {


public:
	tuple<OpposingDriver*, OpposingDriver*> GenerateTeam(string DriverName1, string DriverName2, int difficulty, bool lowDiff=false);
	~A_Opposing_Team();
};

#endif
