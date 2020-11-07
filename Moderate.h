#ifndef MODERATE_H
#define MODERATE_H

#include "Preparedness.h"

class Moderate : public Preparedness {
private:
    int preparedness;
public:
    Moderate(Statistics *stats);
    int getPreparedness();
    virtual ~Moderate();
};

#endif
