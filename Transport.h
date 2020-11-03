#ifndef TRANSPORT_H
#define TRANSPORT_H

class Transport {

private:
	vector<BluePrint*> Transport;
	int NoCars;

public:
	void AddCar(BluePrint* car);

	BluePrint* RemoveCar();
};

#endif
