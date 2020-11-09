#ifndef OVERALL_H
#define OVERALL_H

#include "Performance_Indicator.h"

class Overall : public Performance_Indicator {

private:
	Statistics* Overall_Stats;
public:
    Overall(Concrete_Base_Car_Measurements *subj);
    void ObserveStats();//update method
	void UpdateOverall_Stats(Statistics* Stats);//apply new updates to overallstats
	Statistics* getOverallStats();
	Statistics* getStats();
	virtual ~Overall();
};

#endif
