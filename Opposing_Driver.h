#ifndef OPPOSING_DRIVER_H
#define OPPOSING_DRIVER_H

#include "Statistics.h"
#include "A_Opposing_Driver.h"

class Opposing_Driver : public A_Opposing_Driver {
public:
    // gen a driver based on skills
    virtual Statistics* GenDriver(int skills);

    virtual ~Opposing_Driver();
};

#endif
