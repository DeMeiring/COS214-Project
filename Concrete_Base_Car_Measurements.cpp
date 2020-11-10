#include "Concrete_Base_Car_Measurements.h"

#include <iostream>
#include <string>

using namespace std;

Concrete_Base_Car_Measurements::Concrete_Base_Car_Measurements(Engineering *car) : Base_Car_Measurements(car)
{
    this->component_subject=car;
    this->subject_iterator = component_subject->createIterator(car);
}

Concrete_Base_Car_Measurements::~Concrete_Base_Car_Measurements()
{
    delete subject_iterator;
	delete component_subject;

    subject_iterator = nullptr;
    component_subject = nullptr;
}

void Concrete_Base_Car_Measurements::Observe_car(){

    string attributename;
    int compValue;
    string deptName;

    for(int i = 0; i < 4; i++) //change departments
    { 
        deptName = subject_iterator->CurrentDept()->getRnDName();
        cout << "==========Department: "<< deptName << "===========" << endl;

        for(int j = 0; j < 3; j++) // change components
        {
            attributename = subject_iterator->CurrentDept()->getComponentList(component_subject)[j];
            compValue = subject_iterator->CurrentComp()->getStats()->getAllValues()[j];
            cout << "--------------------------" << endl;
            cout << ">> Component's Name: " << attributename << endl;
            cout << ">> Component's Value: " << compValue << endl;
            cout << "--------------------------" << endl;

            this->stats->ChangeValue(attributename, compValue, false, false);
            // get next component
            this->component_subject= this->subject_iterator->NextComp();
        }
        cout << "=================================================" << endl;

        //get next department
        this->component_subject= this->subject_iterator->NextDept();

    }
    set(this->component_subject);
}

void Concrete_Base_Car_Measurements::set(Engineering* component)
{
    vector<Performance_Indicator*> indicators = getIndicators();
    vector<Performance_Indicator*>::iterator iter = indicators.begin();
    for(iter=indicators.begin();iter!=indicators.end();++iter){
        (*iter)->UpdateOverall_Stats(component->getStats());
    }
}

Statistics*Concrete_Base_Car_Measurements::getStats()
{
    return this->stats;
}



