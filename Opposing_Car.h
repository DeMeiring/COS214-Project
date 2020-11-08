#ifndef OPPOSING_CAR_H
#define OPPOSING_CAR_H

#include "A_Opposing_Car.h"
#include "Department.h"
#include "Component.h"

class Opposing_Car : public A_Opposing_Car {
public:

    virtual Engineering* GenCar(int dif);

    virtual ~Opposing_Car();
};

#endif
