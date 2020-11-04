#include "Race_Crew.h"

void Race_Crew::ReceiveCommand(Command* command) {
	string interpret = command->getCommand();
	// do stuff with command if applicable
}

void Race_Crew::SendCommand(int i) {
	if(i==0) {
		Command* rc = new Race_Command(rs, this, "Base_Command");
		rc->ForwardCommand();
		delete rc;
	}

}

void Race_Crew::showAvailableCommands() {
	// print list of relevant commands for choosing
}
