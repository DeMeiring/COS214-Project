#include "Race_Crew.h"
#include "Radio_System.h"

Race_Crew::Race_Crew() {}

Race_Crew::Race_Crew(Radio_System* rs) {
    this->rs = rs;
}

void Race_Crew::ReceiveCommand(Command* command) {
	string interpret = command->getCommand();
	// do stuff with command if applicable
}

void Race_Crew::SendCommand(Command* command) {
	command->ForwardCommand();
}

void Race_Crew::showAvailableCommands() {
	// print list of relevant commands for choosing
}

Race_Crew::~Race_Crew() {};

Radio_System* Race_Crew::getRS() {
    return rs;
}