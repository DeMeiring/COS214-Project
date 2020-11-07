#ifndef A_BASE_CAR_H
#define A_BASE_CAR_H

#include "Engineering.h"
#include "Engineering_Iterator.h"
#include "BluePrint.h"

class A_Base_Car {

private:
	Engineering* Components;
	Engineering_Iterator* Iterator;
	BluePrint* CarBluePrint;

protected:
	BluePrint* CreateBluePrint();

	void RestoreCar(BluePrint* CarBP);

	A_Base_Car* PrototypeCar();

public:
	Engineering* getComponents();

	void updateComponents(Engineering* newComponents);

	Engineering_Iterator* get_Iter();
};

#endif
