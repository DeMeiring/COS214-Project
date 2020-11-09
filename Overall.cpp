#include "Overall.h"

Overall::Overall(Concrete_Base_Car_Measurements *subj) : Performance_Indicator(subj)
{
	
}

Overall::~Overall()
{
    delete this->Overall_Stats;
    Overall_Stats= nullptr;
}

Statistics* Overall::UpdateOverall_Stats(Statistics* Stats)
{
    setStats(Stats);
    return this->updatedStats;
}

Statistics *Overall::getStats() {
    return Performance_Indicator::getStats();
}




