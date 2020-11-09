#ifndef ROOKIE_H
#define ROOKIE_H

#include "Skill_Level.h"

class Rookie : public Skill_Level {
private:
    int racing_ability;
public:
    Rookie(Statistics *skillModifier);
    int getRacingAbility();
    virtual ~Rookie();
};

#endif
