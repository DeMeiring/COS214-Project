#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <vector>
#include <string>
#include "BluePrint.h"
using namespace std;

class Transport {

private:
	vector<BluePrint*> transport;

public:
    Transport();

    virtual ~Transport();

	void AddCar(BluePrint* car);

	BluePrint* RemoveCar();
};

#endif
