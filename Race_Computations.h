#ifndef RACE_COMPUTATIONS_H
#define RACE_COMPUTATIONS_H

class Race_Computations {


public:
	boolean OvertakeSuccess(tuple<Driver*, Engineering*> ToBeOvertaken, tuple<Driver*, Engineering*> Overtaker);

	boolean ChanceOfCrash(Driver* driver, Engineering* car);

private:
	boolean ChanceOfRecovery(Driver* driver);

public:
	boolean ChanceOfPitOvertake(Driver* adam);
};

#endif
