#include "Client.h"

Client::Client() {
    stage = new Engineering_Stage();
}

Client::~Client() {

}

void Client::SetStage(Stage* set) {
	stage = set;
}

void Client::run() {
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
