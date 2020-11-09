#ifndef ENGINEERING_STAGE_H
#define ENGINEERING_STAGE_H
#include <iostream>
#include <stdlib.h>

#include "Stage.h"
#include "A_Base_Car.h"
#include "Engineering_Iterator.h"
#include "Department.h"
#include "Component.h"
#include "Transport.h"
#include "BluePrint.h"
#include "Car_factory.h"

class Client;

class Engineering_Stage : public Stage {
    private:
        Engineering_Iterator *car_iterator;
        Engineering *Car;
        int budget;
        
    public:
        int choice3;
        int choice2;
        Engineering_Stage(Client* cl);
        string convertCost(int cost);
        void setBudget(int budget);
        int getBudget();
        Engineering_Iterator* getCarIterator();
        void Engineering_main();
        void init();
        Engineering* selectDepartment();
        void setEngineering_Iterator(Engineering_Iterator*);
        virtual ~Engineering_Stage();

        virtual Stage* ChangeStage(int Stage);
        virtual void RunStage();

        //EngineeringStage -> create 4 Departments (of type Engineering, because they are all engineering departments), and from there we add leaves/Components to the Departments.
};

#endif
