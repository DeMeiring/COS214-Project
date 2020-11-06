#ifndef BAHRAIN_H
#define BAHRAIN_H

#include "Track.h"

class Bahrain : public Track {
public:

    Bahrain();

    virtual ~Bahrain();

    virtual string getName();

	virtual string getCornerTypes();

	virtual Statistics* getBuffs();

    virtual Statistics* getDebuffs();

	virtual string getFunFact();
};

#endif
