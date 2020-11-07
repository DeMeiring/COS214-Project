#include "Pro.h"

Pro::Pro(Statistics *skillModifier, Driver *driver) : Skill_Level(skillModifier, driver) {
    this->racing_ability=40;
}

int Pro::getRacingAbility() {
    return racing_ability;
}
