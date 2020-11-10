#ifndef DRIVER_MANAGEMENT_H
#define DRIVER_MANAGEMENT_H

#include "Driver.h"

class Driver_Management {

private:
	vector<Driver*> hired_drivers;
	vector<std::string> available_drivers;
	vector<int> costPerDriver;
    int budget;
public:
    Driver_Management();

    void SetBudget(int buget);

    int getBudget();

	void showAvailableDrivers();

	void purchase_driver(int index, int budget);

	int release_driver(Driver* release);

	vector<Driver*> getVector();

	~Driver_Management();
};

#endif
