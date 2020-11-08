#ifndef CAR_FACTORY_H
#define CAR_FACTORY_H
#include "A_Car_Factory.h"
#include "A_Base_Car.h"

class Car_factory : A_Car_Factory {

public:
	A_Base_Car* ConstructCar();
};

#endif
