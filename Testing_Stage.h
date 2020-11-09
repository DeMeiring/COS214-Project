#ifndef TESTING_STAGE_H
#define TESTING_STAGE_H

#include "Stage.h"
#include "Driver_Management.h"
#include "Concrete_Base_Car_Measurements.h"

class Testing_Stage : public Stage {
private:
    Driver_Management* Manager;

public:
	Testing_Stage(Client *cl);
	virtual ~Testing_Stage();
	void TestingStage_main();
	void pushDrivers();
	void pushOverall();

    virtual Stage* ChangeStage(int Stage);

    virtual void RunStage();
};

#endif
