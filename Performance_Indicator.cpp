#include "Performance_Indicator.h"

Performance_Indicator::Performance_Indicator(Concrete_Base_Car_Measurements* subj)
{
    this->Car_Measurements = subj;
}

Statistics* Performance_Indicator::getStats()
{   
    return Car_Measurements->getTestSubject()->getStats();
}

Performance_Indicator::~Performance_Indicator()
{
    delete this->Car_Measurements;
    this->Car_Measurements= nullptr;
}
