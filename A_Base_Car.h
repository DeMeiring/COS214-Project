#ifndef A_BASE_CAR_H
#define A_BASE_CAR_H

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

	Engineering_iterator* get_Iter();
};

#endif
