#ifndef PERFORMANCE_INDICATOR_H
#define PERFORMANCE_INDICATOR_H
#include "Statistics.h"


class Concrete_Base_Car_Measurements;

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
	
	virtual void UpdateOverall_Stats(Statistics* stats) = 0; // virtual update for over all components

};

#endif
