#include "Individual_Component.h"
#include "Performance_Indicator.h"

#include <iostream>
#include <string>

using namespace std;

Individual_Component::Individual_Component(Concrete_Base_Car_Measurements *subj) : Performance_Indicator(subj)
{
    this->component_subject = subj;

}

void Individual_Component::observeStats()
{
    string comp;
    int comp_value;
    
    for(int i = 0; i < 3; i++)
    {
        pI->getStats()->
    }
    
}

Individual_Component::~Individual_Component()
{
    delete component_stats;

    component_stats = nullptr;
}
