#ifndef OPPOSING_TEAM_H
#define OPPOSING_TEAM_H

#include "A_Opposing_Team.h"

class Opposing_Team : public A_Opposing_Team {
private:
    vector < tuple<string, Driver*, Engineering*> > team;
public:
    vector <tuple<string, Driver*, Engineering*>> GenerateTeam(string DriverName1, string DriverName2, int difficulty);
};

#endif
