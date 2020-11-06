#ifndef COMPONENT_H
#define COMPONENT_H

#include <stdlib.h>
#include <vector>

#include "Engineering.h"
#include "Statistics.h"
using namespace std;

struct component_values {
	int level = 0;
	string name;
	int cost;
};

class Component : public Engineering 
{
private:
	int Cost;
	Statistics* Stats;
	int Level;
	vector<Statistics*> Stat_Levels;

public:
	Component(string name, bool isDept);
	void addDepartment(Engineering *Dept);
	int getCost();

	Statistics getStats();

	bool ChangeLevel(int lvl);
};

#endif
