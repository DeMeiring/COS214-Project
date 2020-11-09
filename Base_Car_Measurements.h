#ifndef BASE_CAR_MEASUREMENTS_H
#define BASE_CAR_MEASUREMENTS_H

#include "Engineering.h"
#include "Performance_Indicator.h"

#include <string>

class Base_Car_Measurements {

private:
	Engineering* Test_Subject; //car
	Engineering* Test_Subject_Component; //component of  car
	vector<Performance_Indicator*> Indicators; //fill indicator

public:
	Base_Car_Measurements(Engineering* car);

	void attach_Indicator(Performance_Indicator* PI); //method for adding observers to vector

	void ComponentChange(); //this will be notifier(update call)

	Engineering* getTestSubject();

	vector<Performance_Indicator*> getIndicators();

	virtual ~Base_Car_Measurements();

};

#endif
