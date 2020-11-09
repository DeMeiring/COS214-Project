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

Stage* Testing_Stage::ChangeStage(int Stage) {
    if(Stage==1)
        Stage::getClient()->SetStage(Stage::getClient()->getStages()[1]);
    else
        Stage::getClient()->SetStage(Stage::getClient()->getStages()[3]);
}

void Testing_Stage::RunStage() {
    TestingStage_main();
}