#ifndef PIT_STOP_H
#define PIT_STOP_H

#include "Tyres.h"
#include <string>

using namespace std;

class Pit_Stop {
private:

    struct tyre_swap {
        string type;
        int delay;
        Tyres* tyre;
    };

	bool car_is_damaged;
	bool tyre_swap;
    int tyre_swaps = 2;
    bool fast_pit;

public:
    void carDamged(bool state);
    void tyreSwap(bool swap, int tyre_type);
    void fastPit(bool fast);
	void Pit_stop_main();
};

#endif
