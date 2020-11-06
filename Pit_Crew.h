#ifndef PIT_CREW_H
#define PIT_CREW_H

#include "Race_Crew.h"
#include "Pit_Stop.h"
#include "Radio_System.h"
#include <iostream>

class RaceDay_stage;

class Pit_Crew : public Race_Crew {
private:
    Pit_Stop* Pit;
    RaceDay_stage *rds;
public:
    Pit_Crew(Radio_System* rs, RaceDay_stage* rstage);
    void runPit();
    virtual ~Pit_Crew();

    virtual void ReceiveCommand(Command* command);
    virtual void SendCommand(int i);

};

#endif
