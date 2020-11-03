#ifndef OVERALL_H
#define OVERALL_H

class Overall : Performance_Indicator {

private:
	Statistics* Overall_Stats;

	void UpdateOverall_Stats(Statistics* Stats);
};

#endif
