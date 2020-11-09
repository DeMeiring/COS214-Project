#include "RaceDay_stage.h"
#include "Pit_Crew.h"
#include <cstdlib>
#include "Client.h"

RaceDay_Stage::RaceDay_Stage(Client* cl) : Stage(cl) {
    rs = new Conc_Radio_System();
	weather = new Weather_Selector;
	PitStop = new Pit_Crew(rs, this);
    RC = Race_Computations::GetComp();

    generateConditions(false);
    TrackInfo();
    generateRacers();

    Engineering *teamCar= User->getCars()->RemoveCar()->getCarBluePrint();

    OpposingDriver *hold = new OpposingDriver();
    hold->driver = User->getHired()[0];
    hold.


    OpposingDrivers.push_back()
}

RaceDay_Stage::~RaceDay_Stage() {
	delete tracks;
	delete weather;
	delete rs;
}

void RaceDay_Stage::generateConditions(bool isRand) {
    // choose track
    show_tracks();
    int decision = 1;
    cin >> decision;
    tracks = ChooseTrack(decision);

    // choose weather
    showWeatherOptions();
    cin >> decision;
    chooseWeather(decision);
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
	cout << "Choose Track" << endl ;
	cout << " 1 -> Bahrain " << endl ;
	cout << " 2 -> Monaco " << endl ;
	cout << " 3 -> Monza" << endl ;
	cout << "4 -> randomize" << endl;
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
	else if(i==3) {
		weather->nextState();
		weather->nextState();
	}
	else
	    randomizeWeather();
}

void RaceDay_Stage::showWeatherOptions() {
	cout << "Weather Options:" << endl ;
	cout << " 1 -> Dry " << endl ;
	cout << " 2 -> Wet " << endl ;
	cout << " 3 -> Raining" << endl ;
}

//=================================================

void RaceDay_Stage::TrackInfo() {
    cout << "Welcome to: " << tracks->getName() << endl;
    cout << tracks->getFunFact() << endl;
    cout << tracks->getName() << "is known for " << tracks->getCornerTypes() << endl;
    lap_count = tracks->getNumLaps();
}

void RaceDay_Stage::Qualifying_Main() {
    cout << "The cars warmup to begin qualifying" << endl;
}

void RaceDay_Stage::MainRace_Main() {
	// TODO - implement RaceDay_Stage::MainRace_Main
	throw "Not yet implemented";
}