#ifndef CONCRETE_BASE_CAR_MEASUREMENTS_H
#define CONCRETE_BASE_CAR_MEASUREMENTS_H

#include "Engineering.h"
#include "Engineering_Iterator.h"
#include "Base_Car_Measurements.h"

class Concrete_Base_Car_Measurements : public Base_Car_Measurements {

private:
	Engineering_Iterator* subject_iterator;  //car iterator
	Engineering* component_subject;  //component of car
	Statistics* stats;

public:
    Concrete_Base_Car_Measurements(Engineering *car);
	virtual ~Concrete_Base_Car_Measurements();

	void Observe_car();
	
	Statistics* getStats();
	void set(Engineering* component);

};

#endif
