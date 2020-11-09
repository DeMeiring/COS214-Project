#include <iostream>
#include "Driver_Management.h"
#include "Radio_System.h"
#include <algorithm>

void Driver_Management::showAvailableDrivers() {
	std::vector<std::string>::iterator it = this->available_drivers.begin();
	int count=0;
	for(it = available_drivers.begin();it!=available_drivers.end();++it){
        std::cout<<count<<":" <<(*it)<<" cost:"<<costPerDriver.at(count);
        count++;
	}
}

void Driver_Management::purchase_driver(int index, int budget) {
    budget = budget - costPerDriver.at(index);

    Driver *purchasedDriver = new Driver(new Conc_Radio_System(), new Statistics(), available_drivers.at(index),costPerDriver.at(index));

    hired_drivers.push_back(purchasedDriver);
}

int Driver_Management::release_driver(Driver* release) {
    int contractCost = release->getContractCost();
    vector<Driver*>::iterator iter;
    for(iter = hired_drivers.begin(); iter < hired_drivers.end(); iter++)
        if((*iter)->getName()==release->getName())
            break;
    hired_drivers.erase(iter);
    return contractCost;
}

vector<Driver *> Driver_Management::getVector() {
    return this->hired_drivers;
}
