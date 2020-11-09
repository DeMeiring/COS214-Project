#ifndef SKILL_LEVEL_H
#define SKILL_LEVEL_H

#include <functional>

#include "Statistics.h"
#include "Driver.h"

class Skill_Level {

private:
	Statistics* skill_modifier;
	Driver* driver;
public:
    Skill_Level(Driver* driver,Statistics* skill_modifier);
    virtual ~Skill_Level();
	Statistics* getSkill_Modifier();
	virtual Driver* getDriver();

	virtual int getRacingAbility() = 0;
};

#endif
