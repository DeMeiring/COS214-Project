#ifndef RACEDAY_STAGE_H
#define RACEDAY_STAGE_H

#include "Stage.h"

#include "Bahrain.h"
#include "Monaco.h"
#include "Monza.h"

#include "Weather.h"

#include "Race_Computations.h"
#include "Radio_System.h"
#include "Teams.h"
#include "Pit_Crew.h"
#include <vector>
#include <iostream>
#include "Conc_Radio_System.h"
#include "Concrete_Base_Car_Measurements.h"
#include "Strategy_Team.h"

#include <unistd.h>
//usleep(10)

class RaceDay_Stage : public Stage {

private:

	bool *Driver_Pit;
	int lap_count;
	Track* tracks;
	Weather_Selector* weather;
	vector<OpposingDriver*> OpposingDrivers;
	Race_Computations* RC;
	Pit_Crew *PitStop;
	Radio_System* rs;
	Statistics *overall;
	Teams* team;
	Strategy_Team* strat_team;


	int IN_one=18, IN_two=19;
    vector<OpposingDriver*> UserDrivers;

    Concrete_Base_Car_Measurements* BCM;

    void MovetoEnd(int i);

	bool PIT;

	//===================================
	void show_tracks();
	Track* ChooseTrack(int index);
	
	void showWeatherOptions();
	void randomizeWeather();
	void chooseWeather(int index);
	void generateConditions(bool isRand);
	void generateRacers();
	void TrackInfo();

public:

    RaceDay_Stage();
    RaceDay_Stage(Client* cl);

    void toPit(bool pit);

	void Qualifying_Main();

	void MainRace_Main();

	void final_grid();

	virtual ~RaceDay_Stage();

    virtual Stage* ChangeStage(int Stage);

    virtual void RunStage();

};

#endif
