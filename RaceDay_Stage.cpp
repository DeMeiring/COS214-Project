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

    OpposingDriver *hold = new OpposingDriver();
    hold->driver = User->getHired()[0];
    hold->car  = User->getCars()->RemoveCar()->getCarBluePrint();
    hold->name = hold->driver->getName();
    hold->team = User->getTeamName();
    OpposingDrivers.push_back(hold);

    hold->driver = User->getHired()[1];
    hold->car  = User->getCars()->RemoveCar()->getCarBluePrint();
    hold->name = hold->driver->getName();
    hold->team = User->getTeamName();
    OpposingDrivers.push_back(hold);

    overall = User->getCar_stats();

    BCM = new Concrete_Base_Car_Measurements(nullptr);

    vector<OpposingDriver*>::iterator iter;

    for(iter= OpposingDrivers.begin(); iter < OpposingDrivers.end(); iter++) {
        BCM->set((*iter)->car);
        (*iter)->overall = BCM->Observe_car();
    }



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
    cout << "The race is " << lap_count << "laps" << endl;
}

bool CompareOverall(Statistics *one, Statistics* two) {
    int ione, itwo;
    ione = itwo =0;

    if(one->getValue("speed") > two->getValue("speed")) {
        ione++;
    }
    else
        itwo++;

    if(one->getValue("acceleration") > two->getValue("acceleration")) {
        ione++;
    }
    else
        itwo++;

    if(one->getValue("weight") > two->getValue("weight")) {
        ione++;
    }
    else
        itwo++;

    if(one->getValue("handling") > two->getValue("handling")) {
        ione++;
    }
    else
        itwo++;

    if(one->getValue("failure") > two->getValue("failure")) {
        ione++;
    }
    else
        itwo++;

    return (ione > itwo);

}

void RaceDay_Stage::Qualifying_Main() {
    cout << "The cars warmup to begin qualifying" << endl;
    // sorting algorithm
    // bubble or selection sort
    OpposingDriver* hold;
    int j=0;

    for(int i=0; i<4; i++) {
        cout << "Heat " << i+1 << " of qualifying" <<endl;
        for(int j = 20 - i*5, k=0; k<(j-1); k++) {
            if(!CompareOverall(OpposingDrivers[k]->overall, OpposingDrivers[k+1]->overall)) {
                cout << OpposingDrivers[k+1]->name << " overtakes " << OpposingDrivers[k]->name << " in the pole" << endl;
                hold = OpposingDrivers[k];
                OpposingDrivers[k] = OpposingDrivers[k+1];
                OpposingDrivers[k+1] = hold;
            }
        }
    }
    cout << "Qualifying completed" << endl;
    cout << "Results: " << endl;
    for(int i=0; i<20; i++) {
        cout << i << ": " << OpposingDrivers[i]->name << endl;
    }
}

void RaceDay_Stage::MainRace_Main() {
    cout << << endl;
}