#include "Statistics.h"

Statistics::Statistics(bool isCar, bool isDriver, bool isComp, bool isOther) {
	if(isCar || isComp) {
		init_car_stats(isComp);
		return;
	}
	else if(isDriver){
		init_driver_stats();
		return;
	}
	else {
		// do nothing
	}
}

void Statistics::addStat(string name, int value) {
	single_stat *n = new single_stat;
	n->name = name;
	n->stat = value;
	values.push_back(n);
}

void Statistics::init_driver_stats() {
	addStat("racing_ability", 33);

	addStat("preparedness", 0);

	addStat("dry", 60);

	addStat("wet", 40);

	addStat("raining", 25);

	addStat("aggression", 45);

	addStat("conservation", 70);

}

void Statistics::init_car_stats(bool isCar) {
	// base car
	if(isCar) {
		addStat("speed", 50);

		addStat("acceleration", 50);

		addStat("weight", 50);

		addStat("handling", 50);

		addStat("failure", 50);
	}
	// component
	else {
		addStat("speed", 0);

		addStat("acceleration", 0);

		addStat("weight", 0);

		addStat("handling", 0);

		addStat("failure", 0);
	}

}

bool Statistics::ChangeValue(string find, int value, bool append, bool inc) {
	vector<single_stat*>::iterator iter;
	for(iter = values.begin(); iter<values.end(); iter++) {
		if((*iter)->name==find) {
			if(append==false) {
				(*iter)->stat = value;
				return;
			}
			else if(append==true) {
				if(inc==true) {
					(*iter)->stat += value;
					return;	
				}
				else {
					(*iter)->stat -= value;
					return;
				}
			}
		}
	}
	// value was not found
}

int Statistics::getValue(string find) {
	vector<single_stat*>::iterator iter;
	for(iter = values.begin(); iter<values.end(); iter++) {
		if((*iter)->name==find) {
			return (*iter)->stat;
		}
	}
}

