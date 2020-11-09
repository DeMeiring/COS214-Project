#include "BluePrint.h"

Engineering* BluePrint::getCarBluePrint() {
	return CarBluePrint;
}

void BluePrint::setCarBluePrint(Engineering* CarBluePrint) {
	this->CarBluePrint = CarBluePrint;
}

BluePrint::~BluePrint() {

}
