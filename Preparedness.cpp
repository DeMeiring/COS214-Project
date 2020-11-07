#include "Preparedness.h"

Statistics* Preparedness::getSkill_Modifier() {
	return this->skill_modifier;
}

Preparedness::Preparedness(Statistics *stats) {
    this->skill_modifier = stats;
}

Preparedness::~Preparedness() {
    delete this->skill_modifier;
}
