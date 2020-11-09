#ifndef PREPAREDNESS_H
#define PREPAREDNESS_H

#include "Statistics.h"

class Preparedness {

private:
	Statistics* skill_modifier;

public:
    Preparedness(Statistics* stats);
	Statistics* getSkill_Modifier();
	virtual ~Preparedness();

	virtual int getPreparedness() = 0;
};

#endif
