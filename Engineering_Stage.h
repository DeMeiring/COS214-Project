#ifndef ENGINEERING_STAGE_H
#define ENGINEERING_STAGE_H
#include <iostream>
#include <stdlib.h>


// #include "Client.h"
// #include "Stage.h"
 #include "A_Base_Car.h"
 #include "Engineering_Iterator.h"
#include "Department.h"
#include "Component.h"
#include "Car_factory.h"


class Engineering_Stage {
    private:
        Engineering_Iterator *car_iterator;
        Engineering *Car;
    public:
        Engineering_Iterator* getCarIterator();
        void Engineering_main();
        void init();
        void selectDepartment();
        void setEngineering_Iterator(Engineering_Iterator*);

        //EngineeringStage -> create 4 Departments (of type Engineering, because they are all engineering departments), and from there we add leaves/Components to the Departments.
};

#endif
