#ifndef TESTING_STAGE_H
#define TESTING_STAGE_H

#include "Stage.h"
#include "Performance_Indicator.h"
#include "Base_Car_Measurements.h"
#include "Overall.h"
#include "Concrete_Base_Car_Measurements.h"
#include "Driver_Management.h"

using namespace std;

class Testing_Stage :public Stage {
    Driver* driver;
    Engineering* car;
    Performance_Indicator* observer;
    Base_Car_Measurements* concreteBase;
    Driver_Management* dm;
    Client* cli;

public:
	Testing_Stage(Client *cl);
	//setters
	void setDriver(Driver* driver);
	void setCar(Engineering*car);
    void setObserver(Performance_Indicator* observer);
    void setConcreteBase(Base_Car_Measurements*concreteBase);
    virtual Stage* ChangeStage(int Stage);
    void RunStage();
    //getters
    Driver* getDriver();
    Engineering* getCar();
    Performance_Indicator* getObserver();
    Base_Car_Measurements* getConcreteBase();

	void TestingStage_main();
    virtual ~Testing_Stage();
};

#endif
