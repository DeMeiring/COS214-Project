#ifndef STAGE_H
#define STAGE_H

#include "Driver.h"
#include "Engineering.h"

class Client;

class Stage {

protected:
	Client* User;
	Stage* curr_stage;

public:

    Stage(Client* cl);

    Client* getClient();

    void updateStage(Stage* set);

    Stage* getStage();

	virtual Stage* ChangeStage(int Stage)=0;

	virtual void RunStage()=0;
};

#endif
