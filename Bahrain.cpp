#include "Bahrain.h"

Bahrain::Bahrain() : Track(55) {
}

Bahrain::~Bahrain() {

}

string Bahrain::getName() {
    return "Bahrain";
}

string Bahrain::getCornerTypes() {
    return "Hair-pins with long straights";
}

Statistics* Bahrain::getBuffs() {
    // gen and return
}

Statistics* Bahrain::getDebuffs() {
    // gen and return
}

string Bahrain::getFunFact() {
    return "Bahrain is only the third race track to have taken place at night";
}