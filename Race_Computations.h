#ifndef RACE_COMPUTATIONS_H
#define RACE_COMPUTATIONS_H

using namespace std;

class Race_Computations {


public:

	bool OvertakeSuccess(tuple<Driver*, Engineering*> ToBeOvertaken, tuple<Driver*, Engineering*> Overtaker);

	bool ChanceOfCrash(Driver* driver, Engineering* car);

	bool ChanceOfPitOvertake(Driver* adam);

private:
	bool ChanceOfRecovery(Driver* driver);
	
};

#endif
