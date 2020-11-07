#ifndef AGGRESSIVE_H
#define AGGRESSIVE_H

#include "RaceDay_Strat.h"
#include "Statistics.h"

class Aggressive : public RaceDay_Strat {
    private:
        int aggression;
        int conservative;
        
    public:
        Aggressive(Statistics *skillModifier);
        virtual ~Aggressive();

        int getAggression();
        int getConservative();

};

#endif
