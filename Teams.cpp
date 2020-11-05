#include "Teams.h"

string names[] = {"Hamilton", "Bottas", "Verstappen", "Albon", "Ricciardo", "Ocon", "Vettel", "Leclerc"
					, "Sainz", "Norris", "Gasly", "Kvyat", "Perez", "Stroll", "Raikonen", "Giovinazzi"
					, "Russel", "Latifi"};

string teams[] = {"Mercedes", "Red-Bull Racing", "Renault", "Ferrari", "McLaren", "AlphaTauri", "Racing Point", "Alfa Romeo", 
					"Williams"};


// create a bunch of drivers
Teams::Teams() {
	OppTeamFact = new Opposing_Team();

	tuple<OpposingDriver*, OpposingDriver*> rec;

	rec = OppTeamFact->GenerateTeam(names[0], names [1], 94, true);
	get<0>(rec)->team = teams[0];
	OpposingDrivers.push_back(get<0>(rec));
	get<1>(rec)->team = teams[0];
	OpposingDrivers.push_back(get<1>(rec));

	rec = OppTeamFact->GenerateTeam(names[2], names [3], 88, false);
	get<0>(rec)->team = teams[1];
	OpposingDrivers.push_back(get<0>(rec));
	get<1>(rec)->team = teams[1];
	OpposingDrivers.push_back(get<1>(rec));

	// renault
	rec = OppTeamFact->GenerateTeam(names[4], names [5], 80, false);
	get<0>(rec)->team = teams[2];
	OpposingDrivers.push_back(get<0>(rec));
	get<1>(rec)->team = teams[2];
	OpposingDrivers.push_back(get<1>(rec));

	// ferarri
	rec = OppTeamFact->GenerateTeam(names[6], names [7], 84, true);
	get<0>(rec)->team = teams[3];
	OpposingDrivers.push_back(get<0>(rec));
	get<1>(rec)->team = teams[3];
	OpposingDrivers.push_back(get<1>(rec));

	// mclaren
	rec = OppTeamFact->GenerateTeam(names[8], names [9], 75, true);
	get<0>(rec)->team = teams[4];
	OpposingDrivers.push_back(get<0>(rec));
	get<1>(rec)->team = teams[4];
	OpposingDrivers.push_back(get<1>(rec));

	// alphatauri
	rec = OppTeamFact->GenerateTeam(names[10], names [11], 72, false);
	get<0>(rec)->team = teams[5];
	OpposingDrivers.push_back(get<0>(rec));
	get<1>(rec)->team = teams[5];
	OpposingDrivers.push_back(get<1>(rec));

	// rp
	rec = OppTeamFact->GenerateTeam(names[12], names [13], 70, true);
	get<0>(rec)->team = teams[6];
	OpposingDrivers.push_back(get<0>(rec));
	get<1>(rec)->team = teams[6];
	OpposingDrivers.push_back(get<1>(rec));

	// ar
	rec = OppTeamFact->GenerateTeam(names[14], names [15], 55, true);
	get<0>(rec)->team = teams[7];
	OpposingDrivers.push_back(get<0>(rec));
	get<1>(rec)->team = teams[7];
	OpposingDrivers.push_back(get<1>(rec));

	// williams
	rec = OppTeamFact->GenerateTeam(names[16], names [17], 65, false);
	get<0>(rec)->team = teams[8];
	OpposingDrivers.push_back(get<0>(rec));
	get<1>(rec)->team = teams[8];
	OpposingDrivers.push_back(get<1>(rec));

}

vector<OpposingDriver*> Teams::getOpposingDrivers() {
	return OpposingDrivers;
}

Teams::~Teams() {
	vector<OpposingDriver*>::iterator iter;
	for(iter = OpposingDrivers.begin(); iter < OpposingDrivers.end(); iter++)
		delete (*iter);
	OpposingDrivers.clear();
}