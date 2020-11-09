#include "Base_Car_Measurements.h"

Base_Car_Measurements::Base_Car_Measurements(Engineering* car) {
	this->Test_Subject = car;
}

void Base_Car_Measurements::attach_Indicator(Performance_Indicator* PI) {
    Indicators.push_back(PI);
}

void Base_Car_Measurements::ComponentChange() {
    vector<Performance_Indicator*>::iterator it = Indicators.begin();
    for(it=Indicators.begin();it!=Indicators.end();++it){
        (*it)->observeStats();
    }
}

Engineering* Base_Car_Measurements::getTestSubject() {
    return this->Test_Subject;
}
