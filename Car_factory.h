#ifndef CAR_FACTORY_H
#define CAR_FACTORY_H
#include "A_Car_Factory.h"
#include "Department.h"
#include "Component.h"

class Car_factory : public A_Car_Factory{

public:
	Engineering* ConstructCar();

	virtual ~Car_factory();

};

#endif
