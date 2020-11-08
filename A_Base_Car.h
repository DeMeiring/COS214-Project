#ifndef A_BASE_CAR_H
#define A_BASE_CAR_H
#include "Engineering.h"
class Engineering_Stage;

class BluePrint;

class A_Base_Car {

private:
	Engineering* Components;
	Engineering_Iterator* Iterator;
	BluePrint* CarBluePrint;

protected:
	BluePrint* CreateBluePrint(Engineering* copy);

	void RestoreCar(BluePrint* CarBP);

public:

	Engineering* PrototypeCar(Engineering *composite);

	Engineering* getComponents();

	void updateComponents(Engineering* newComponents);

	Engineering_Iterator* get_Iter();
};

#endif
