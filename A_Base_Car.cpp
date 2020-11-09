#include "A_Base_Car.h"
#include "BluePrint.h"
#include "Engineering_Stage.h"
//test 2 of base

BluePrint* A_Base_Car::CreateBluePrint(Engineering* copy) { //at the end of the main, copy constructor to make a copy
	BluePrint *blueprint = new BluePrint();
	blueprint->setCarBluePrint(PrototypeCar(copy));
	CarBluePrint = blueprint;
	return CarBluePrint;
}

void A_Base_Car::RestoreCar(BluePrint* CarBP) {
	// TODO - implement A_Base_Car::RestoreCar
	
}

Engineering* A_Base_Car::PrototypeCar(Engineering* composite) {//recieves engineering, iterate through components, return a new Engineering
	// TODO - implement A_Base_Car::PrototypeCar
	//iterate through all components+departments an copy over to new Engineering objects
	A_Car_Factory* factory = new Car_factory();

//original iterator
	Engineering_Iterator *iterator = new Engineering_Iterator(composite);
	
//copy iterator
	Engineering* copyCar = new Department("Chassis", true);
	copyCar = factory->ConstructCar();	
	Engineering_Iterator *copyIterator = new Engineering_Iterator(copyCar);

	for (int i = 0; i < 12; i ++)
	{
		copyIterator->CurrentComp()->ChangeLevel(iterator->CurrentComp()->getLevel());
		copyIterator->NextComp();
		iterator->NextComp();
	}
	copyIterator->resetCurrComp();
	iterator->resetCurrComp();
	return copyIterator->FirstDept();
}

