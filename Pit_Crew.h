#ifndef PIT_CREW_H
#define PIT_CREW_H

#include "Race_Crew.h"
#include "Pit_Stop.h"

class RaceDay_Stage;

class Pit_Crew : public Race_Crew {
private:
    Pit_Stop* Pit;
    RaceDay_Stage *rds;
public:
    Pit_Crew(Radio_System* rs, RaceDay_Stage* rstage);
    void runPit();
    virtual ~Pit_Crew();

    virtual void ReceiveCommand(Command* command);
    virtual void SendCommand(int i);

};

#endif
