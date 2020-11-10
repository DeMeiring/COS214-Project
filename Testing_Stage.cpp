#include "Testing_Stage.h"
#include "Engineering_Stage.h"

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
    auto eng = new Engineering_Stage(this->cli);
    auto EngineeringIt = eng->getCarIterator();
    auto car =  EngineeringIt->FirstDept();
    Driver_Management* dm = new Driver_Management();

    int budget;
    cout << "----------------------------" << endl;
    cout << " Enter a Driver's budget: " << endl;
    cout << "----------------------------" << endl;
    cin >> budget;
    cout << endl;

    dm->SetBudget(budget);

    for(int i = 0; i < 2; i++)
    {
        cout << "+===============================+" << endl;
        dm->showAvailableDrivers();
        cout << "+===============================+" << endl;
        cout << endl;

        cout << "++++++++++++++++++++++++++++" << endl;
        cout << "Please select a driver: " << endl;
        cout << "++++++++++++++++++++++++++++" << endl;
        int input;
        cin >> input;
        cout << endl;

        dm->purchase_driver(input, budget);
    }


    cout<<"Hired drivers are:"<<endl;
    vector<Driver*> hiredDrivers = dm->getVector();
    std::vector<Driver*>::iterator it = hiredDrivers.begin();
    for(it=hiredDrivers.begin();it!=hiredDrivers.end();it++){
        cout<<"Driver:"<< (*it)->getName()<<endl;
    }
    cout<<"Remaining budget: "<<dm->getBudget()<<endl;

    cout<<endl;
    cout << "###########################################" << endl;
    cout << "##                                       ##" << endl;
    cout << "##          RUNNING THE TESTING          ##" << endl;
    cout << "##                                       ##" << endl;
    cout << "###########################################" << endl;

    auto* concBase = new Concrete_Base_Car_Measurements(car);

    concBase->Observe_car();
}

Testing_Stage::Testing_Stage(Client *cl) : Stage(cl) {
    this->driver=driver;
    this->car=car;
    this->observer=observer;
    this->concreteBase=concreteBase;
    this->cli = cli;
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

Stage *Testing_Stage::ChangeStage(int Stage) {
    return nullptr;
}

void Testing_Stage::RunStage() {}
