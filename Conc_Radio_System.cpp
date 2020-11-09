#include "Conc_Radio_System.h"

void Conc_Radio_System::addGroup(Race_Crew* group) {
	if(RaceTeam.size()==0)
		RaceTeam.push_back(group);
	else {
		vector<Race_Crew*>::iterator hold;
		for(hold = RaceTeam.begin(); hold<RaceTeam.end(); hold++) {
			if(group == (*hold)) {
				//throw "Error";
				return;
			}
		}
		RaceTeam.push_back(group);
	}
}

void Conc_Radio_System::PushCommand(Race_Crew* RaceMember, Command* command) {
	vector<Race_Crew*>::iterator hold;
	for(hold = RaceTeam.begin(); hold<RaceTeam.end(); hold++) {
		if(RaceMember != *(hold)) {
			(*hold)->ReceiveCommand(command);
		}
	}	
}

Conc_Radio_System::~Conc_Radio_System() {}
