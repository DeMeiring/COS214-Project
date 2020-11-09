#include "Skill_Level.h"

Skill_Level::Skill_Level(Driver* driver,Statistics *skill_modifier) {
    this->skill_modifier = skill_modifier;
    this->driver=driver;
}

Skill_Level::~Skill_Level() {
    delete this->skill_modifier;
}

Statistics* Skill_Level::getSkill_Modifier() {
 return this->skill_modifier;
}

Driver* Skill_Level::getDriver() {
    return this->driver;
}
