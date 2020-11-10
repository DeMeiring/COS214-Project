#include "Testing_Stage.h"


Testing_Stage::~Testing_Stage() {
    delete this->driver;
    delete this->car;
    delete this->observer;
    delete this->concreteBase;
    this->driver= nullptr;
    this->car= nullptr;
    this->observer= nullptr;
    this->concreteBase= nullptr;
}

void Testing_Stage::TestingStage_main()
{
    // dm->showAvailableDrivers();

    Driver_Management* dm = new Driver_Management();

    cout << "===============================" << endl;
    cout << "Available Drivers : " << dm->showAvailableDrivers() << endl;
    cout << "===============================" << endl;
    cout << endl;
    cout << "Please select a driver: " << endl;
    int input;

    dm->purchase_driver(input, )

}

Testing_Stage::Testing_Stage(Driver *driver, Engineering *car, Performance_Indicator *observer, Base_Car_Measurements *concreteBase) {
    this->driver=driver;
    this->car=car;
    this->observer=observer;
    this->concreteBase=concreteBase;

}

void Testing_Stage::setDriver(Driver *driver)
{
    this->driver=driver;
}

void Testing_Stage::setCar(Engineering *car)
{
    this->car=car;
}

void Testing_Stage::setObserver(Performance_Indicator *observer)
{
    this->observer = observer;
}

void Testing_Stage::setConcreteBase(Base_Car_Measurements *concreteBase)
{
    this->concreteBase=concreteBase;
}

Driver *Testing_Stage::getDriver()
{
    return this->driver;
}

Engineering *Testing_Stage::getCar()
{
    return this->car;
}

Performance_Indicator *Testing_Stage::getObserver()
{
    return this->observer;
}

Base_Car_Measurements *Testing_Stage::getConcreteBase()
{
    return this->concreteBase;
}
