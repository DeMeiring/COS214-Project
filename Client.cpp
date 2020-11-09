#include "Client.h"

Client::Client() {
    Stages.push_back(new Engineering_Stage(this));
    Stages.push_back(new Testing_Stage(this));
    Stages.push_back(new RaceDay_Stage(this));
}

Client::~Client() {

}

void Client::SetStage(Stage* set) {
	stage = set;
}

void Client::run() {
    cout << "Welcome to team The Raikkoning is coming's interactive F1 Sim" << endl;
    cout << "Please enter a team name" << endl;
    getline(cin, teamName);

	while(kill_switch)
	    stage->RunStage();
}

Transport* Client::getCars() {
	return Cars;
}

void Client::setCars(Transport* Cars) {
	this->Cars = Cars;
}

Statistics* Client::getCar_stats() {
	return this->car_stats;
}

void Client::setCar_stats(Statistics* car_stats) {
	this->car_stats = car_stats;
}

void Client::setHired(vector<Driver*> hired) {
    this->hired = hired;
}

vector<Driver*> Client::getHired() {
    return this->hired;
}

string Client::getTeamName() {
    return teamName;
}

vector<Stage*> Client::getStages() {
    return Stages;
}