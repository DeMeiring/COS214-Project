#ifndef ENGINEERING_STAGE_H
#define ENGINEERING_STAGE_H

#include "Client.h"
#include "Stage.h"
#include "A_Base_Car.h"
#include "Engineering_Iterator.h"

class Engineering_Stage {
    private:
        Engineering_Iterator *car_iterator;
        A_Base_Car *Car;
    public:
        void Engineering_main();
};

#endif
