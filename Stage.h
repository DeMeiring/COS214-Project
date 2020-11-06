#ifndef STAGE_H
#define STAGE_H

#include "Driver.h"
#include "Engineering.h"

class Client;

class Stage {

protected:
	Client* User;

public:
	void ChangeStage(int Stage);

	void RunStage();
};

#endif
