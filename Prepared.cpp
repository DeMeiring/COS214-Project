#include "Prepared.h"

Prepared::Prepared(Statistics *stats) : Preparedness(stats) {
    this->prepared=100;
}

int Prepared::getPreparedness() {
    return this->prepared;
}

Prepared::~Prepared()
{

}
