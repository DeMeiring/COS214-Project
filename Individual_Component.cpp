#include "Individual_Component.h"

void Individual_Component::printComponentStats() {

}

void Individual_Component::observeStats() {
    Performance_Indicator::observeStats();
}

Individual_Component::Individual_Component(Concrete_Base_Car_Measurements *subj) : Performance_Indicator(subj) {

}

Individual_Component::~Individual_Component() {

}
