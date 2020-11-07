#include "Experienced.h"

Experienced::Experienced(Statistics *skillModifier, Driver *driver) : Skill_Level(skillModifier, driver) {
    this->racing_ability=30;
}

int Experienced::getRacingAbility() {
    return this->racing_ability;
}

