#include "Performance_Indicator.h"
#include "Concrete_Base_Car_Measurements.h"

Performance_Indicator::Performance_Indicator(Concrete_Base_Car_Measurements* subj)
{
    this->Car_Measurements = subj;
}

Statistics* Performance_Indicator::getStats()
{   
    return this->updatedStats;
}

Performance_Indicator::~Performance_Indicator()
{
    delete this->Car_Measurements;
    this->Car_Measurements= nullptr;
}

void Performance_Indicator::setStats(Statistics *stats) {
    this->updatedStats=new Statistics;
}
