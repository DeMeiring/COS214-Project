#include "RaceDay_stage.h"
#include "Pit_Crew.h"
#include <cstdlib>

RaceDay_Stage::RaceDay_Stage() {
	weather = new Weather_Selector;
}

RaceDay_Stage::~RaceDay_Stage() {
	delete tracks;
}

void RaceDay_Stage::generateConditions(bool isRand) {
	if(isRand) {
		randomizeWeather();
		return;
	}
	else {
		// generate here?
	}
}

void RaceDay_Stage::generateRacers() {
	Teams *teams = new Teams();
	teams->GenDrivers();
	OpposingDrivers = teams->getOpposingDrivers();
	delete teams;
}

Track* RaceDay_Stage::ChooseTrack(int index) {
	if(index==1)
		tracks = new Bahrain();
	else if(index==2)
		tracks = new Monaco();
	else if(index==3)
		tracks = new Monza();
}

void RaceDay_Stage::show_tracks() {
	cout << "Choose Tracks" << endl ;
	cout << " 1 -> Bahrain " << endl ;
	cout << " 2 -> Monaco " << endl ;
	cout << " 3 -> Monza" << endl ;
}

void RaceDay_Stage::randomizeWeather() {
	int i = 1 + rand() % 3;

	if(i==1)
		return;
	else if(i==2)
		weather->nextState();
	else {
		weather->nextState();
		weather->nextState();
	}
}

void RaceDay_Stage::chooseWeather(int i) {
	if(i==1)
		return;
	else if(i==2)
		weather->nextState();
	else {
		weather->nextState();
		weather->nextState();
	}
}

void RaceDay_Stage::showWeatherOptions() {
	cout << "Weather Options:" << endl ;
	cout << " 1 -> Dry " << endl ;
	cout << " 2 -> Wet " << endl ;
	cout << " 3 -> Raining" << endl ;
}

//=================================================


void RaceDay_Stage::Qualifying_Main() {
	// TODO - implement RaceDay_Stage::Qualifying_Main
	throw "Not yet implemented";
}

void RaceDay_Stage::MainRace_Main() {
	// TODO - implement RaceDay_Stage::MainRace_Main
	throw "Not yet implemented";
}