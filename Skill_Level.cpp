#include "Skill_Level.h"

Skill_Level::Skill_Level(Statistics *skill_modifier) {
    this->skill_modifier = skill_modifier;
}

Skill_Level::~Skill_Level() {
    delete this->skill_modifier;
}

Statistics* Skill_Level::getSkill_Modifier() {
 return this->skill_modifier;
}

//Driver* Skill_Level::getDriver() {
    //return this->driver;
//}
