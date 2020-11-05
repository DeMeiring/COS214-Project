#ifndef A_OPPOSING_CAR_H
#define A_OPPOSING_CAR_H

#include "Statistics.h"
#include "Engineering.h"
#include <tuple>

class A_Opposing_Car {


public:
	virtual Engineering* GenCar(int dif)=0;

	~A_Opposing_Car();
};

#endif
