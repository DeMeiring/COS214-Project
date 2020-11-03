#ifndef DRIVER_MANAGEMENT_H
#define DRIVER_MANAGEMENT_H

class Driver_Management {

private:
	vector<Driver*> hired_drivers;
	vector<tuple<string, name>> available_drivers;

public:
	void showAvailableDrivers();

	Driver* purchase_driver(int index, int budget);

	int release_driver(Driver* release);
};

#endif
