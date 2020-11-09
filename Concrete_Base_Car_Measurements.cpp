#include "Concrete_Base_Car_Measurements.h"
Concrete_Base_Car_Measurements::Concrete_Base_Car_Measurements(Engineering *car) : Base_Car_Measurements(car) {
    this->component_subject=car;
    this->subject_iterator = component_subject->createIterator(car);
}

void Concrete_Base_Car_Measurements::Observe_car(){
    std::string attributename;
    int compValue;
    for(int i=0;i<4;i++){ //change departments
        for(int j=0;j<3;j++){
            attributename=subject_iterator->CurrentDept()->getComponentList(component_subject)[j];
            
            compValue=subject_iterator->CurrentComp()->getStats()->getValue("handling");

        }
        this->component_subject= this->subject_iterator->NextDept();
    }
    //check and eval current component

    //update current component

}

void Concrete_Base_Car_Measurements::set(Engineering* Comp) {
	this->component_subject=Comp;
}



