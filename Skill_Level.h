#ifndef SKILL_LEVEL_H
#define SKILL_LEVEL_H

#include <functional>

#include "Statistics.h"
#include "Driver.h"

class Skill_Level {

private:
	Statistics* skill_modifier;

public:
    Skill_Level(Statistics* skill_modifier);
    virtual ~Skill_Level();
	Statistics* getSkill_Modifier();
	Driver* getDriver();

	virtual int getRacingAbility() = 0;
};

#endif
