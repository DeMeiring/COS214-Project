#ifndef PERFORMANCE_INDICATOR_H
#define PERFORMANCE_INDICATOR_H

class Performance_Indicator {

protected:
	Concrete_Base_Car_Measurements* Car_Measurements;

public:
	Performance_Indicator(Concrete_Base_Car_Measurements* subj);

	void observeStats();

	statistics getStats();
};

#endif
