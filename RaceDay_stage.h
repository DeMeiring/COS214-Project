#ifndef RACEDAY_STAGE_H
#define RACEDAY_STAGE_H

class RaceDay_Stage : Stage {

private:
	boolean Diver_Pit;
	int lap_count;
	vector<track*> tracks;
	Weather* weather;
	vector<string> OppDriverNames;
	int tyre_strategy;

public:
	void generateConditions();

	void Qualifying_Main();

	void MainRace_Main();

	void generateRacers();

private:
	void ChooseTrack(int index);

	void show_tracks();

	void randomizeWeather();

	void chooseWeather(int index);

	void showWeatherOptions();

public:
	void operation();
};

#endif
