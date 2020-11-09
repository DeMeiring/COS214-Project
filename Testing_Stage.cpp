#include "Testing_Stage.h"
#include "Client.h"

Testing_Stage::Testing_Stage(Client *cl) : Stage(cl)  {
    Manager = new Driver_Management();
}

Testing_Stage::~Testing_Stage() {

}

void Testing_Stage::TestingStage_main() {

}

void Testing_Stage::pushDrivers() {
     // get vector
    User->setHired(Manager->getVector());
}

void Testing_Stage::pushOverall() {
    // get overall

}