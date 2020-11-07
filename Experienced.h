#ifndef EXPERIENCED_H
#define EXPERIENCED_H
#include "Skill_Level.h"

class Experienced : public Skill_Level {
private:
    int racing_ability;
public:
    Experienced(Statistics *skillModifier, Driver *driver);
    int getRacingAbility();
    virtual ~Experienced();
};

#endif
