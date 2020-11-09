#ifndef CLIENT_H
#define CLIENT_H
#include "Stage.h"
#include "Transport.h"
#include "Statistics.h"

#include "Stage.h"
#include "Engineering.h"
#include "Transport.h"
#include "Driver.h"
#include "Statistics.h"
#include "Track.h"

#include "Engineering_Stage.h"
#include "RaceDay_stage.h"
#include "Testing_Stage.h"


using namespace std;

class Client {

private:
	Stage* stage; // state
	Transport* Cars; // momento for cars of custom drivers
	Statistics* car_stats; // total stats for user cars
	vector<Driver*> hired; // has drivers
	bool kill_switch;

	vector<Stage*> Stages;

	string teamName; // team name

public:

	Client();
	virtual ~Client();

	void SetStage(Stage* set);

	void run();

	Transport* getCars();

	void setCars(Transport* Cars);

	Statistics* getCar_stats();

	void setCar_stats(Statistics* car_stats);

	void setHired(vector<Driver*> hired);

    vector<Driver*> getHired();

    string getTeamName();

    vector<Stage*> getStages();

};

#endif
