#ifndef PIT_STOP_H
#define PIT_STOP_H

#include "Soft.h"
#include "Medium.h"
#include "Hard.h"
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

    void carDamged(bool state);
    void tyreSwap(int tyre_type);
    void fastPit(bool fast);
	int Pit_stop_main(Race_Computations *rc);
};

#endif
