#ifndef CONSERVATIVE_H
#define CONSERVATIVE_H

#include "RaceDay_Strat.h"
#include "Statistics.h"

class Conservative : public RaceDay_Strat {
    private:
        int aggression;
        int conservative;

    public:
        Conservative(Statistics *skillModifier);
        virtual ~Conservative();

        int getAggression();
        int getConservative();

};

#endif
