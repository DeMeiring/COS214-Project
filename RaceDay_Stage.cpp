#include "RaceDay_stage.h"
#include "Pit_Crew.h"
#include <cstdlib>
#include "Client.h"
#include "Opposing_Car.h"
#include "Opposing_Driver.h"

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

    UserDrivers.push_back(hold);

    hold->driver = User->getHired()[1];
    hold->car  = User->getCars()->RemoveCar()->getCarBluePrint();
    hold->name = hold->driver->getName();
    hold->team = User->getTeamName();
    OpposingDrivers.push_back(hold);

    UserDrivers.push_back(hold);

    overall = User->getCar_stats();

    BCM = new Concrete_Base_Car_Measurements(nullptr);

    vector<OpposingDriver*>::iterator iter;
    Driver_Pit = new bool[2];

    //for(iter= OpposingDrivers.begin(); iter < OpposingDrivers.end(); iter++) {
    //    BCM->set((*iter)->car);
    //    (*iter)->overall = BCM->Observe_car();
    //}

}

Stage* RaceDay_Stage::ChangeStage(int Stage) {
    Stage::getClient()->Kill();
    return nullptr;
}

void RaceDay_Stage::RunStage() {
    Qualifying_Main();
    MainRace_Main();
    ChangeStage(555);
}

void RaceDay_Stage::toPit(bool pit) {
    Driver_Pit[0] =true;
    Driver_Pit[1] = true;
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
	else
		tracks = new Monza();
	return tracks;
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
        if(OpposingDrivers[i]==UserDrivers[0])
            IN_one=i;
        if(OpposingDrivers[i]==UserDrivers[1])
            IN_two=i;
    }
}

void RaceDay_Stage::MovetoEnd(int i) {
    OpposingDriver *hold;
    hold = OpposingDrivers[i];
    for(int j = i; j<19; j++) {
        OpposingDrivers[j] = OpposingDrivers[j+1];
    }
    OpposingDrivers[19] = hold;
}

void RaceDay_Stage::MainRace_Main() {
    int w_in = 1;
    cout << "The main race begins" << endl;

    if (weather->getState()->getName() == "dry") {
        cout << "A nice sunny day here in " << tracks->getName() << endl;
    } else if (weather->getState()->getName() == "wet") {
        w_in = 2;
        cout << "The track today seems a bit slippery in " << tracks->getName() << endl;
    } else {
        w_in = 3;
        cout << "A spectacle today as the track is experiencing rain here in" << tracks->getName() << endl;
    }

// =================================================
    for (int i = 1; i < lap_count + 1; i++) {
        cout << "Lap " << i << "/" << lap_count << endl;
        _sleep(2);
        system("clear");


        if((Driver_Pit[0]==true) || (Driver_Pit[1]==true)) {
            PitStop->runPit();
        }
        else if ((i % 5) == 0) {
            system("clear");
            _sleep(5);
            cout << "All the focus is on the new team:" << UserDrivers[0]->team << " as the race continues" << endl;

            // randomize number of chances to overtake
            // overtake forward
            Racers *OverTaker = new Racers;
            Racers *OverTaken = new Racers;

            for (int i = 0; i < (1 + rand() + 3); i++) {
                if (IN_one == IN_two - 1 || IN_two == IN_one - 1) {
                    cout << "race order has been given to not overtake team mates" << endl;
                    break;
                }

                if (IN_one == 0 || UserDrivers[0]->crashed == false) {
                    cout << UserDrivers[0]->name << " leads the race for now" << endl;
                    break;
                } else if (UserDrivers[0]->crashed == false) {

                    OverTaken->Car = OpposingDrivers[IN_one - 1]->car->getStats();
                    OverTaken->Racer = OpposingDrivers[IN_one - 1]->driver->getStats();
                    OverTaken->TyresOfCar = OpposingDrivers[IN_one - 1]->tyre;


                    OverTaken->Car = OpposingDrivers[IN_one]->car->getStats();
                    OverTaken->Racer = OpposingDrivers[IN_one]->driver->getStats();
                    OverTaken->TyresOfCar = OpposingDrivers[IN_one]->tyre;

                    OpposingDriver *pass;
                    if (RC->OvertakeSuccess(OverTaken, OverTaker)) {
                        cout << "An impressive overtake on" << OpposingDrivers[IN_one - 1]->name << " by "
                             << OpposingDrivers[IN_one] << endl;
                        pass = OpposingDrivers[IN_one];
                        OpposingDrivers[IN_one] = OpposingDrivers[IN_one - 1];
                        OpposingDrivers[IN_one - 1] = pass;

                    }
                }
                // =================================================
                if (IN_two == 0 || UserDrivers[1]->crashed == false) {
                    cout << UserDrivers[1]->name << " leads the race for now" << endl;
                    break;
                } else if (UserDrivers[1]->crashed == false) {
                    Racers *OverTaken = new Racers;
                    OverTaken->Car = OpposingDrivers[IN_two - 1]->car->getStats();
                    OverTaken->Racer = OpposingDrivers[IN_two - 1]->driver->getStats();
                    OverTaken->TyresOfCar = OpposingDrivers[IN_two - 1]->tyre;

                    Racers *OverTaker = new Racers;
                    OverTaken->Car = OpposingDrivers[IN_two]->car->getStats();
                    OverTaken->Racer = OpposingDrivers[IN_two]->driver->getStats();
                    OverTaken->TyresOfCar = OpposingDrivers[IN_two]->tyre;

                    OpposingDriver *pass;
                    if (RC->OvertakeSuccess(OverTaken, OverTaker)) {
                        cout << "An impressive overtake on" << OpposingDrivers[IN_two - 1]->name << " by "
                             << OpposingDrivers[IN_two] << endl;
                        pass = OpposingDrivers[IN_two];
                        OpposingDrivers[IN_two] = OpposingDrivers[IN_two - 1];
                        OpposingDrivers[IN_two - 1] = pass;
                    }
                }
                // =================================================
            }
            // =================================================
            for (int i = 0; i < (1 + rand() + 3); i++) {
                if (IN_one == IN_two - 1 || IN_two == IN_one - 1) {
                    cout << "race order has been given to not overtake team mates" << endl;
                    break;
                }

                if (IN_one == 19) {
                    cout << "Team " << UserDrivers[0]->team << "has a driver running last" << endl;
                } else {
                    Racers *OverTaker = new Racers;
                    OverTaken->Car = OpposingDrivers[IN_one + 1]->car->getStats();
                    OverTaken->Racer = OpposingDrivers[IN_one + 1]->driver->getStats();
                    OverTaken->TyresOfCar = OpposingDrivers[IN_one + 1]->tyre;

                    Racers *OverTaken = new Racers;
                    OverTaken->Car = OpposingDrivers[IN_one]->car->getStats();
                    OverTaken->Racer = OpposingDrivers[IN_one]->driver->getStats();
                    OverTaken->TyresOfCar = OpposingDrivers[IN_one]->tyre;

                    OpposingDriver *pass;
                    if (RC->OvertakeSuccess(OverTaken, OverTaker)) {
                        cout << "An impressive overtake on" << OpposingDrivers[IN_one]->name << " by "
                             << OpposingDrivers[IN_one + 1] << endl;
                        pass = OpposingDrivers[IN_one + 1];
                        OpposingDrivers[IN_one + 1] = OpposingDrivers[IN_one];
                        OpposingDrivers[IN_one] = pass;
                    }
                }

                if (IN_two == 19) {
                    cout << "Team " << UserDrivers[1]->team << "has a driver running last" << endl;
                } else {
                    Racers *OverTaker = new Racers;
                    OverTaken->Car = OpposingDrivers[IN_two + 1]->car->getStats();
                    OverTaken->Racer = OpposingDrivers[IN_two + 1]->driver->getStats();
                    OverTaken->TyresOfCar = OpposingDrivers[IN_two + 1]->tyre;

                    Racers *OverTaken = new Racers;
                    OverTaken->Car = OpposingDrivers[IN_two]->car->getStats();
                    OverTaken->Racer = OpposingDrivers[IN_two]->driver->getStats();
                    OverTaken->TyresOfCar = OpposingDrivers[IN_two]->tyre;

                    OpposingDriver *pass;
                    if (RC->OvertakeSuccess(OverTaken, OverTaker)) {
                        cout << "An impressive overtake on" << OpposingDrivers[IN_two]->name << " by "
                             << OpposingDrivers[IN_one + 1] << endl;
                        pass = OpposingDrivers[IN_two + 1];
                        OpposingDrivers[IN_two + 1] = OpposingDrivers[IN_two];
                        OpposingDrivers[IN_two] = pass;
                    }
                }
            }

            //============================================================
            delete OverTaken;
            delete OverTaker;
            // =================================================

            // randomize number of chances to be overtaken
            // be overtaken

            // if raining 1/3 dice roll of slipping off track
            // if wet 1/5
            // if wet 1/8

            // compute crash
            // compute recovery

            //kill me now
            bool chance = false;
            int decision = 1 + rand() % 100;
            switch (w_in) {
                case 1: {
                    if (decision < 12) {
                        chance = true;
                    }
                    break;
                }
                case 2: {
                    if (decision < 20) {
                        chance = true;
                    }
                    break;
                }
                case 3: {
                    if (decision < 33) {
                        chance = true;
                    }
                }
            }

            // =================================================
            int car_choice = rand() % 2;

            if (chance) {
                Racers *RC_pass = new Racers;
                RC_pass->TyresOfCar = UserDrivers[car_choice]->tyre;
                RC_pass->Racer = UserDrivers[car_choice]->driver->getStats();
                RC_pass->Car = UserDrivers[car_choice]->car->getStats();

                Conditions *cond = new Conditions;
                cond->WeatherCond = weather;
                cond->TrackCond = tracks;

                if (RC->ChanceOfCrash(RC_pass, cond)) {
                    cout << UserDrivers[car_choice]->name << " slides wide on the corner, can they control the car? "
                         << endl;
                    if (RC->ChanceOfRecovery(RC_pass)) {
                        cout << "The driver manages to recover from their mistake with minor damage to the car" << endl;
                        UserDrivers[car_choice]->driver->SendCommand(4);
                        Driver_Pit[car_choice] = true;
                    } else {
                        cout << "The car spins out of control into the wall" << endl;
                        cout << "The race is over for " << UserDrivers[car_choice]->name << endl;
                        if (car_choice == 1) {
                            MovetoEnd(IN_one);
                        } else {
                            MovetoEnd(IN_two);
                        }
                        UserDrivers[car_choice]->crashed = true;
                    }
                }
            }
        }
    }
    final_grid();
}

void RaceDay_Stage::final_grid() {
    cout << "The race comes to a spectacular finish" << endl;
    _sleep(1);
    cout << OpposingDrivers[0]->name << " in 1st" << endl;
    cout << OpposingDrivers[1]->name << " in 2nd" << endl;
    cout << OpposingDrivers[2]->name << " in 3rd" << endl;
    _sleep(3);
    cout << "The rest of the grid is as follows" <<endl;
    _sleep(2);
    for(int i=3; i<20; i++)
        cout<< i << ": " << OpposingDrivers[i]->name << endl;
}