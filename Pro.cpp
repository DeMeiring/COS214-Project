#include "Pro.h"
#include "Skill_Level.h"

Pro::Pro(Statistics *skillModifier) : Skill_Level(skillModifier)
{
    this->racing_ability=40;
}

int Pro::getRacingAbility()
{
    return racing_ability;
}
