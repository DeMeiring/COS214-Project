#include "Transport.h"

void Transport::AddCar(BluePrint* car) {
	transport.clear();
	transport.push_back(car);
}

BluePrint* Transport::RemoveCar() {
	BluePrint *bluePrint = new BluePrint();

	if(transport.empty() != true)
		bluePrint = transport[0];

	return bluePrint;
}

Transport::Transport() {

}

Transport::~Transport() {

}