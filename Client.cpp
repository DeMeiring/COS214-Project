#include "Client.h"

void Client::SetStage() {
	// TODO - implement Client::SetStage
	throw "Not yet implemented";
}

void Client::run() {
	// TODO - implement Client::run
	throw "Not yet implemented";
}

Transport* Client::getCars() {
	// TODO - implement Client::getCars
	throw "Not yet implemented";
}

void Client::setCars(Transport* Cars) {
	// TODO - implement Client::setCars
	throw "Not yet implemented";
}

bool Client::Store_carStats(Statistics* stats) {
	// TODO - implement Client::Store_carStats
	throw "Not yet implemented";
}

Statistics* Client::getCar_stats() {
	return this->car_stats;
}

void Client::setCar_stats(Statistics* car_stats) {
	this->car_stats = car_stats;
}
