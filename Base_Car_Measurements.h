#ifndef BASE_CAR_MEASUREMENTS_H
#define BASE_CAR_MEASUREMENTS_H

class Base_Car_Measurements {

private:
	Engineering* Test_Subject;
	Engineering* Test_Subject_Component;
	vector<Performance_Indicator*> Indicators;

public:
	Base_Car_Measurements(Engineering* car);

	void attach_Indicator(Performance_Indicator* PI);

	void ComponentChange();
};

#endif
