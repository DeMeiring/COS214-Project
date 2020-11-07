#include "Experienced.h"

Experienced::Experienced(Statistics *skillModifier) : Skill_Level(skillModifier)
{
    this->racing_ability=30;
}

int Experienced::getRacingAbility()
{
    return this->racing_ability;
}

