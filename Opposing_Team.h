#ifndef OPPOSING_TEAM_H
#define OPPOSING_TEAM_H

#include "A_Opposing_Team.h"
#include "A_Opposing_Car.h"
#include "A_Opposing_Driver.h"

// this struct may need to be moved
struct OpposingDriver {
		string team;
		string name;
		Driver* driver;
		Engineering* car;
	};

class Opposing_Team : public A_Opposing_Team {
private:
    A_Opposing_Car *OppCarFact;
	A_Opposing_Driver *OppDrivFact;
public:
    tuple<OpposingDriver*, OpposingDriver*> GenerateTeam(string DriverName1, string DriverName2, int difficulty, bool lowDiff=false);
};

#endif
