#ifndef PREPARED_H
#define PREPARED_H

#include "Preparedness.h"

class Prepared :public Preparedness {
private:
    int prepared;
public:
    Prepared(Statistics *stats);
    int getPreparedness();
    virtual ~Prepared();
};

#endif
