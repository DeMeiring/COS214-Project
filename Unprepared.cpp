#include "Unprepared.h"

Unprepared::Unprepared(Statistics *stats) : Preparedness(stats) {
    this->preparedness=33;
}

int Unprepared::getPreparedness() {
    return this->preparedness;
}

Unprepared::~Unprepared() {

}

