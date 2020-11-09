#ifndef INDIVIDUAL_COMPONENT_H
#define INDIVIDUAL_COMPONENT_H

#include "Performance_Indicator.h"
#include "Concrete_Base_Car_Measurements.h"

class Individual_Component : public Performance_Indicator {

    private:
        Statistics* component_stats; //local stats that have to be updated
        Performance_Indicator* pI; // performance indicator

    public:
        Individual_Component(Concrete_Base_Car_Measurements *subj);
        virtual ~Individual_Component();
        
        void observeStats();

};

#endif
