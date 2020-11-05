#include "Teams.h"

string names[] = {""};
string teams[] = {""};


// create a bunch of drivers
Teams::Teams() {
	OppCarFact = new Opposing_Car();
	OppDrivFact = new Opposing_Driver();
}

Driver* Teams::getDriverbyName(string name) {
	// TODO - implement Teams::getDriverbyName
	throw "Not yet implemented";
}

Driver* Teams::getDriver(int index) {
	// TODO - implement Teams::getDriver
	throw "Not yet implemented";
}

Teams::~Teams() {
}