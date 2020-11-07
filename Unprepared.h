#ifndef UNPREPARED_H
#define UNPREPARED_H

#include "Preparedness.h"

class Unprepared : public Preparedness {
private:
    int preparedness;
public:
    Unprepared(Statistics *stats);
    int getPreparedness();
    virtual ~Unprepared();
};

#endif
