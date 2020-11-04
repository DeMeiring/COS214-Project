#ifndef A_OPPOSING_TEAM_H
#define A_OPPOSING_TEAM_H

#include <tuple>
#include <vector>
#include "Driver.h"
#include "Engineering.h"

using namespace std;

class A_Opposing_Team {


public:
	virtual vector <tuple<string, Driver*, Engineering*>> GenerateTeam(string DriverName1, string DriverName2, int difficulty)=0;

	~A_Opposing_Team();
};

#endif
