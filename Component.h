#ifndef COMPONENT_H
#define COMPONENT_H

#include <stdlib.h>
#include <vector>

#include "Engineering.h"
#include "Statistics.h"
using namespace std;

class Component : public Engineering 
{
private:
	vector<int> Chas_Costs;
	vector<int> Aero_Costs;
	vector<int> Eng_Costs;
	vector<int> Elec_Costs;
	Statistics* stats;
	int level;
	vector<Statistics*> Stat_Levels;
	int cost;

public:
	Component(string name, bool isDept, int level);

	void setCost(int cost);

	int getCost();

	void addDepartment(Engineering *);

	Statistics getStats();

	bool ChangeLevel(int lvl);
};

#endif
