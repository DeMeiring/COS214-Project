#ifndef MONZA_H
#define MONZA_H

#include "Track.h"

class Monza : public Track {
public:

    Monza();

    virtual ~Monza();

    virtual string getName();

	virtual string getCornerTypes();

	virtual Statistics* getBuffs();

    virtual Statistics* getDebuffs();

	virtual string getFunFact();
};

#endif
