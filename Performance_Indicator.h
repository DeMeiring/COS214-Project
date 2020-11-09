#ifndef PERFORMANCE_INDICATOR_H
#define PERFORMANCE_INDICATOR_H
#include "Concrete_Base_Car_Measurements.h"
#include "Statistics.h"

class Performance_Indicator {

protected:
	Concrete_Base_Car_Measurements* Car_Measurements;

public:
	Performance_Indicator(Concrete_Base_Car_Measurements* subj);

	void observeStats();

	Statistics* getStats();

	virtual void UpdateOverall_Stats(Statistics* stats)=0;

	virtual ~Performance_Indicator();
};

#endif
