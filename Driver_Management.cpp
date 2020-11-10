#include <iostream>
#include "Driver_Management.h"
#include "Conc_Radio_System.h"
#include <algorithm>

Driver_Management::Driver_Management()
{
    costPerDriver.push_back(500000);
    costPerDriver.push_back(400000);
    costPerDriver.push_back(100000);
    costPerDriver.push_back(300000);
    costPerDriver.push_back(300000);

    available_drivers.push_back("Liam");
    available_drivers.push_back("Matt");
    available_drivers.push_back("DeVilliers");
    available_drivers.push_back("Dean");
    available_drivers.push_back("Joseph");
}

void Driver_Management::showAvailableDrivers() {
	std::vector<std::string>::iterator it = this->available_drivers.begin();
	int count=0;
	for(it = available_drivers.begin();it!=available_drivers.end();++it){
        std::cout << count<< ": " << (*it) << "->" << " Cost: " << costPerDriver.at(count) << endl;
        count++;
	}
}

void Driver_Management::purchase_driver(int index, int budget) {
    if(this->budget - costPerDriver.at(index)<=0){
        cout<<"Can not afford the driver.";
        cout<<endl;
    }else{
        this->budget = this->budget - costPerDriver.at(index);

        Driver *purchasedDriver = new Driver(new Conc_Radio_System(), new Statistics(), available_drivers.at(index),costPerDriver.at(index));

        hired_drivers.push_back(purchasedDriver);
    }
}

int Driver_Management::getBudget() {
    return this->budget;
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

Driver_Management::~Driver_Management() {

}

void Driver_Management::SetBudget(int budget) {
    this->budget=budget;
}
