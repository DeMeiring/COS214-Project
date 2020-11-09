#include "Moderate.h"

Moderate::Moderate(Statistics *stats) : Preparedness(stats) {
    this->preparedness=66;
}

int Moderate::getPreparedness() {
    return this->preparedness;
}
