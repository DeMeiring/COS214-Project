#ifndef PRO_H
#define PRO_H

#include "Skill_Level.h"

class Pro : public Skill_Level {
private:
    int racing_ability;
public:
    Pro(Statistics *skillModifier);
    int getRacingAbility();
    virtual ~Pro();
};

#endif
