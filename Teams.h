#ifndef TEAMS_H
#define TEAMS_H

class Teams {

private:
	vector<tuple<string, Driver*, Engineering*>> OpposingDrivers;

public:
	Driver* getDriverbyName(string name);

	Driver* getDriver(int index);
};

#endif
