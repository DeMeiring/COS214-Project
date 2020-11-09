#ifndef RACE_COMPUTATIONS_H
#define RACE_COMPUTATIONS_H

#include "Driver.h"
#include "Engineering.h"
#include "Weather.h"
#include "Tyres.h"
#include "Track.h"
#include "Statistics.h"

using namespace std;

struct Racers {
    Statistics* Racer;
    Statistics* Car;
    Tyres* TyresOfCar;
};

struct Conditions {
    Weather_Selector *WeatherCond;
    Track *TrackCond;
};

class Race_Computations {
private:

    static Race_Computations* instance; //singleton

    int DistributeValue(double value);

//protected:

    //Race_Computations();

public:

    Race_Computations();

    static Race_Computations* GetComp();

	bool OvertakeSuccess(Racers* ToBeOvertaken, Racers* Overtaker);

	bool ChanceOfCrash(Racers* racer, Conditions* cond);

	int ChanceOfPitOvertake(int delay);

    bool ChanceOfRecovery(Racers* driver);
	
};


#endif
