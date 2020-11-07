#ifndef ENGINEERING_STAGE_H
#define ENGINEERING_STAGE_H
#include <iostream>
#include <stdlib.h>


// #include "Client.h"
// #include "Stage.h"
//  #include "A_Base_Car.h"
// #include "Engineering_Iterator.h"
#include "Department.h"
#include "Component.h"


class Engineering_Stage {
    private:
        Engineering_Iterator *car_iterator;
        // A_Base_Car *Car;
    public:
        void Engineering_main();
        void init();
        void selectDepartment();

        //EngineeringStage -> create 4 Departments (of type Engineering, because they are all engineering departments), and from there we add leaves/Components to the Departments.
};

#endif
