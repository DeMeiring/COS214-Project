#include "Strategy_Team.h"
#include "Radio_System.h"

Strategy_Team::Strategy_Team(Radio_System* rs) : Race_Crew(rs) {

}

void Strategy_Team::ReceiveCommand(Command* command) {
    if(command->getCommand()=="fast_pit?") {
        cout << "Fast pit?" << endl;
        cout << "0 -> No / 1 -> Yes" << endl;
        int in;
        cin >> in;
        if(in==1)
            SendCommand(4);
        else
            SendCommand(5);
    } else if(command->getCommand()=="car_damaged") {
        cout << "Strategy Team: Car damage acknowledged" << endl;
    }
    delete command;
}

void Strategy_Team::SendCommand(int i) {
    switch(i) {
        case 1: {
            Command *command = new Race_Command(Race_Crew::getRS(), this, "change strategy 1"); // conservative
            cout << "Strategy team radios message:" << command->getCommand() << endl;
            Race_Crew::SendCommand(command);
            break;
        }
        case 2: {
            Command *command = new Race_Command(Race_Crew::getRS(), this, "change strategy 2"); // aggressive
            cout << "Strategy team radios message:" << command->getCommand() << endl;
            Race_Crew::SendCommand(command);
            break;
        }
        case 3: {
            Command *command = new Race_Command(Race_Crew::getRS(), this, "change strategy 3"); // risky
            cout << "Strategy team radios message:" << command->getCommand() << endl;
            Race_Crew::SendCommand(command);
            break;
        }
        case 4: {
            Command *command = new Race_Command(Race_Crew::getRS(), this, "yes_fast");
            cout << "Strategy team radios message:" << command->getCommand() << endl;
            Race_Crew::SendCommand(command);
            break;
        }
        case 5: {
            Command *command = new Race_Command(Race_Crew::getRS(), this, "no_fast");
            cout << "Strategy team radios message:" << command->getCommand() << endl;
            Race_Crew::SendCommand(command);
            break;
        }
    }
}
Strategy_Team::~Strategy_Team() {

}

