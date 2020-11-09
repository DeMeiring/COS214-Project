#ifndef BLUEPRINT_H
#define BLUEPRINT_H
#include "A_Base_Car.h"

class BluePrint {

private:
Engineering* CarBluePrint;

public:
	Engineering* getCarBluePrint();

	void setCarBluePrint(Engineering* CarBluePrint);

	virtual ~BluePrint();
};

#endif
