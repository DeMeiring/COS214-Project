#ifndef A_OPPOSING_DRIVER_H
#define A_OPPOSING_DRIVER_H

#include "Driver.h"

class A_Opposing_Driver {


public:
	virtual Driver* GenDriver(int skills)=0;

	virtual ~A_Opposing_Driver();
};

#endif
