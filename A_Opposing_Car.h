#ifndef A_OPPOSING_CAR_H
#define A_OPPOSING_CAR_H

#include "Engineering.h"

class A_Opposing_Car {


public:
	virtual Engineering* GenCar(int dif)=0;
};

#endif
