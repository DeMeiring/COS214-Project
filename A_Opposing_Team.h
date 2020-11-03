#ifndef A_OPPOSING_TEAM_H
#define A_OPPOSING_TEAM_H

class A_Opposing_Team {


public:
	tuple<string, Driver*, Car*> GenerateTeam(string DriverName, int difficulty);
};

#endif
