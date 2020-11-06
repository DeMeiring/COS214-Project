#include "Pit_Crew.h"
#include "RaceDay_stage.h"

Pit_Crew::Pit_Crew(Radio_System* rs, RaceDay_stage* rstage) : Race_Crew(rs) {
    Pit = new Pit_Stop;
    rds = rstage;
}

void Pit_Crew::runPit() {
    Pit->Pit_stop_main();
}

Pit_Crew::~Pit_Crew() {
    delete Pit;
}

void Pit_Crew::SendCommand(int i) {
    switch(i) {
        case 1: {
            Command *command = new Race_Command(Race_Crew::getRS(), this, "box-box");
            cout << "Pit crew radios message:" << command->getCommand() << endl;
            Race_Crew::SendCommand(command);
            break;
        }
        case 2: {
            Command *command = new Race_Command(Race_Crew::getRS(), this, "softs?");
            cout << "Pit crew radios message:" << command->getCommand() << endl;
            Race_Crew::SendCommand(command);
            break;
        }
        case 3: {
            Command *command = new Race_Command(Race_Crew::getRS(), this, "medium?");
            cout << "Pit crew radios message:" << command->getCommand() << endl;
            Race_Crew::SendCommand(command);
            break;
        }
        case 4: {
            Command *command = new Race_Command(Race_Crew::getRS(), this, "hard?");
            cout << "Pit crew radios message:" << command->getCommand() << endl;
            Race_Crew::SendCommand(command);
            break;
        }
        default: {
            Command *command = new Race_Command(Race_Crew::getRS(), this, "fast_pit?");
            cout << "Pit crew radios message:" << command->getCommand() << endl;
            Race_Crew::SendCommand(command);
            break;
        }
    }
}

void Pit_Crew::ReceiveCommand(Command* command) {
    if(command->getCommand()=="yes_soft") {
        Pit->tyreSwap(true, 1);
        SendCommand(1);
    } else if(command->getCommand()=="yes_medium") {
        Pit->tyreSwap(true, 2);
        SendCommand(1);
    } else if(command->getCommand()=="yes_hard") {
        Pit->tyreSwap(true, 3);
        SendCommand(1);
    } else if(command->getCommand()=="yes_fast") {
        Pit->fastPit(true);
        SendCommand(1);
    } else if(command->getCommand()=="car_damaged") {
        Pit->carDamged(true);
        SendCommand(-1);
    } else if(command->getCommand()=="no_soft") {
        SendCommand(2);
    } else if(command->getCommand()=="no_medium") {
        Pit->carDamged(true);
        SendCommand(3);
    }
}