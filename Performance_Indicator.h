#ifndef PERFORMANCE_INDICATOR_H
#define PERFORMANCE_INDICATOR_H
#include "Concrete_Base_Car_Measurements.h"
#include "Statistics.h"

class Performance_Indicator {

protected:
    Concrete_Base_Car_Measurements* Car_Measurements;
    Statistics* updatedStats;
public:
	Performance_Indicator(Concrete_Base_Car_Measurements* subj);
	virtual ~Performance_Indicator();

	virtual Statistics* getStats();

	virtual void setStats(Statistics*);

	virtual void observeStats() = 0; // virtual 'update' for individual components
	
	virtual Statistics* UpdateOverall_Stats(Statistics* stats) = 0; // virtual update for over all components

};

#endif
