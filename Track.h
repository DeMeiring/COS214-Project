#ifndef TRACK_H
#define TRACK_H

class Track {

private:
	int number_of_laps;

public:
	string getName();

	string getCornerTypes();

	Statistics* getBuffs();

	Statistics* getDebuffs();

	string getFunFact();
};

#endif
