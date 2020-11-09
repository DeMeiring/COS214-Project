#include "Rookie.h"

Rookie::Rookie(Statistics *skillModifier) : Skill_Level(skillModifier) {
    this->racing_ability=20;
}

int Rookie::getRacingAbility() {
    return this->racing_ability;
}

Rookie::~Rookie() {}
