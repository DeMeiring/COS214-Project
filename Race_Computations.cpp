#include "Race_Computations.h"
#include "Driver.h"
#include "Engineering.h"
#include <cstdlib>

Race_Computations* Race_Computations:: GetComp() {
    if(instance==0)
        instance = new Race_Computations();
    else
        return instance;
}

bool Race_Computations::OvertakeSuccess(Racers ToBeOvertaken, Racers Overtaker, Conditions cond) {
    // total
    double calc =  0 + ToBeOvertaken.Racer->getStats()->getValue("aggression");
    calc = calc / 100;
    calc *= ToBeOvertaken.Racer->getStats()->getValue("racing_ability");
    //acc
    //spee
    //weight
    calc += cond.WeatherCond->getStats();
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

int Race_Computations::DistributeValue(double value) {
    int x = (int) value;
    int range = 1+ rand() % 100;
    if(range <= x)
        return 1;
    else
        return 0;
}
