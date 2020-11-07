#ifndef RACE_COMPUTATIONS_H
#define RACE_COMPUTATIONS_H

#include "Driver.h"
#include "Engineering.h"
#include "Weather.h"
#include "Tyres.h"
#include "Track.h"

using namespace std;

struct Racers {
    Driver* Racer;
    Engineering* Car;
    Tyres* TyresOfCar;
};

struct Conditions {
    Weather *WeatherCond;
    Track *TrackCond;
};

class Race_Computations {
private:

    static Race_Computations* instance; //singleton

    bool ChanceOfRecovery(Driver* driver);

    int DistributeValue(double value);

protected:

    Race_Computations();

public:

    static Race_Computations* GetComp();

	bool OvertakeSuccess(Racers ToBeOvertaken, Racers Overtaker, Conditions cond);

	bool ChanceOfCrash(Racers racer);

	int ChanceOfPitOvertake(int delay);
	
};

Race_Computations* Race_Computations :: instance = 0;


#endif
