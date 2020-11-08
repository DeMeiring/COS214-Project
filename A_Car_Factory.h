#ifndef A_CAR_FACTORY_H
#define A_CAR_FACTORY_H
//test 3
#include "Engineering.h"

class A_Car_Factory {
    public:
        virtual Engineering *ConstructCar() = 0;
        virtual ~A_Car_Factory();
};

#endif
