#ifndef RACEDAY_STAGE_H
#define RACEDAY_STAGE_H

#include "Stage.h"
#include "Track.h"
#include "Weather.h"
#include "Race_Computations.h"
#include "Radio_System.h"
#include <vector>

class RaceDay_Stage : public Stage {

private:
	bool Diver_Pit;
	int lap_count;
	Track* tracks;
	Weather* weather;
	vector<string> OppDriverNames;
	vector<string> Tracks;
	int* tyre_degradation;
	Race_Computations* RC;

	void show_tracks();
	Track* ChooseTrack(int index);
	
	void showWeatherOptions();
	void randomizeWeather();
	void chooseWeather(int index);

	void generateConditions();

	void generateRacers();

public:

	void Qualifying_Main();

	void MainRace_Main();

	RaceDay_Stage();
	virtual ~RaceDay_Stage();

};

#endif
