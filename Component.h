#ifndef COMPONENT_H
#define COMPONENT_H

class Component : Engineering {

private:
	int Cost;
	Statistics* Stats;
	int Level;
	vector<Statistics*> Stat_Levels;

public:
	int getCost();

	Statistics getStats();

	boolean ChangeLevel(int lvl);
};

#endif
