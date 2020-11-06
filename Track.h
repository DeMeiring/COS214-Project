#ifndef TRACK_H
#define TRACK_H

#include <string>
#include "Statistics.h"

using namespace std;

class Track {

private:
	int number_of_laps;

public:

	Track(int l) {number_of_laps=l;};

	virtual string getName()=0;

	virtual string getCornerTypes()=0;

	virtual Statistics* getBuffs()=0;

	virtual Statistics* getDebuffs()=0;

	virtual string getFunFact()=0;

	int getNumLaps() {return number_of_laps;};
};

#endif
