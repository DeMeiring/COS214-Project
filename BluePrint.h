#ifndef BLUEPRINT_H
#define BLUEPRINT_H
#include "A_Base_Car.h"

class BluePrint {

private:
	A_Base_Car* CarBluePrint;

public:
	A_Base_Car* getCarBluePrint();

	void setCarBluePrint(A_Base_Car* CarBluePrint);
};

#endif