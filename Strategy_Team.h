#ifndef STRATEGY_TEAM_H
#define STRATEGY_TEAM_H

#include "Race_Crew.h"

class Strategy_Team : Race_Crew {
public:
    Strategy_Team(Radio_System* rs);
    virtual ~Strategy_Team();

    virtual void ReceiveCommand(Command* command);
    virtual void SendCommand(int i);

};

#endif
