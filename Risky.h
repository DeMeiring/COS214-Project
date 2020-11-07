#ifndef RISKY_H
#define RISKY_H

#include "RaceDay_Strat.h"
#include "Statistics.h"

class Risky : public RaceDay_Strat {
    private:
        int aggression;
        int conservative;

    public:
        Risky(Statistics* stats);
        virtual ~Risky();

        int getAggression();
        int getConservative();
        

};

#endif
