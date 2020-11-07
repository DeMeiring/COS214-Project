#include "Race_Computations.h"
#include "Driver.h"
#include "Engineering.h"
#include <tuple>

Race_Computations* Race_Computations:: GetComp() {
    if(instance==0)
        instance = new Race_Computations();
    else
        return instance;

}

bool Race_Computations::OvertakeSuccess(Racers ToBeOvertaken, Racers Overtaker, Conditions cond) {
	// TODO - implement Race_Computations::OvertakeSuccess
	throw "Not yet implemented";
}

bool Race_Computations::ChanceOfCrash(Racers racer) {
	// TODO - implement Race_Computations::ChanceOfCrash
	throw "Not yet implemented";
}

bool Race_Computations::ChanceOfRecovery(Driver* driver) {
	// TODO - implement Race_Computations::ChanceOfRecovery
	throw "Not yet implemented";
}

int Race_Computations::ChanceOfPitOvertake(int delay) {
    //COMPUTE DELAY
    if(delay > 12) {
        return (4 + rand() % 8);
    } else if(delay < 5) {
        return (0+rand() % 2);
    } else if(delay < 12 && delay > 5) {
        return (2 + rand() % 5);
    }
}
