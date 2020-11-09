#include "Transport.h"

void Transport::AddCar(BluePrint* car) {
	Transport.clear();
	Transport.push_back(car);
}

BluePrint* Transport::RemoveCar() {
	BluePrint *bluePrint = new BluePrint();

	if(Transport.empty() != true)
		bluePrint = Transport[0];

	return bluePrint;
}
