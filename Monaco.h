#ifndef MONACO_H
#define MONACO_H

#include "Track.h"

class Monaco : public Track {
public:

    Monaco();
    virtual ~Monaco();

    virtual string getName();

	virtual string getCornerTypes();

	virtual Statistics* getBuffs();

    virtual Statistics* getDebuffs();

	virtual string getFunFact();
};

#endif
