#ifndef COMPONENT_H
#define COMPONENT_H

#include <stdlib.h>
#include <vector>

#include "Engineering.h"
#include "Statistics.h"
using namespace std;


class Component : Engineering {

private:
	int Cost;
	Statistics* Stats;
	int Level;
	vector<Statistics*> Stat_Levels;

public:
	int getCost();

	Statistics getStats();

	bool ChangeLevel(int lvl);
};

#endif
