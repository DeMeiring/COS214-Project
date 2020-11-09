#ifndef CONCRETE_BASE_CAR_MEASUREMENTS_H
#define CONCRETE_BASE_CAR_MEASUREMENTS_H

class Concrete_Base_Car_Measurements : Base_Car_Measurements {

private:
	Component_Iterator* subjects;
	Engineering* component_subject;

public:
	void Observe_car();

	void set(Engineering* Comp);

	Engineering* getComponent();

	Concrete_Base_Car_Measurements(Engineering* car);
};

#endif
