#ifndef INDIVIDUAL_COMPONENT_H
#define INDIVIDUAL_COMPONENT_H

#include "Performance_Indicator.h"

class Individual_Component :public Performance_Indicator {
private:
    Statistics* component_stats; //local stats that have to be updated

public:
    Individual_Component(Concrete_Base_Car_Measurements *subj);
    void printComponentStats();
    void observeStats();
    virtual ~Individual_Component();

};

#endif
