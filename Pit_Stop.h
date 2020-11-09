#ifndef PIT_STOP_H
#define PIT_STOP_H

#include "Tyres.h"
#include "Race_Computations.h"

#include <iostream>
#include <string>

using namespace std;

class Pit_Stop {
private:

    struct tyre_swap {
        string type;
        int delay;
        Tyres* tyre;
    };

    tyre_swap* nextTyreSet;

	bool car_is_damaged;
    int tyre_swaps;
    bool fast_pit;

public:

    Pit_Stop();
    virtual ~Pit_Stop();

    void carDamaged(bool state);
    void tyreSwap(int tyre_type);
    void fastPit(bool fast);
	int Pit_stop_main(Race_Computations *rc);
};

#endif
