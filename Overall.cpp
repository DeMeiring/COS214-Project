#include "Overall.h"
#include "Concrete_Base_Car_Measurements.h"

Overall::Overall(Concrete_Base_Car_Measurements *subj) : Performance_Indicator(subj)
{
	
}

Overall::~Overall()
{

}

void Overall::UpdateOverall_Stats(Statistics* Stats)
{
    setStats(Stats);
}

Statistics *Overall::getStats() {
    return Performance_Indicator::getStats();
}




