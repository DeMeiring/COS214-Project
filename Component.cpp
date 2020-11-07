#include "Component.h"

Component::Component(string name, bool isDept, int level):Engineering(name, isDept)
{
	Chas_Costs.push_back(0);
	Chas_Costs.push_back(0);
	Chas_Costs.push_back(1000000);
	Chas_Costs.push_back(5000000);

	Aero_Costs.push_back(0);
	Aero_Costs.push_back(0);
	Aero_Costs.push_back(2000000);
	Aero_Costs.push_back(7000000);

	Eng_Costs.push_back(0);
	Eng_Costs.push_back(0);
	Eng_Costs.push_back(10000000);
	Eng_Costs.push_back(20000000);

	Elec_Costs.push_back(0);
	Elec_Costs.push_back(0);
	Elec_Costs.push_back(12000000);
	Elec_Costs.push_back(22000000);
	
	this->level = level;
	
	if(name == "Chassis")
	{
		if (level == 0)
		{
			Cost = Chas_Costs[0];
		}
		else if(level == 1)
		{
			Cost = Chas_Costs[1];
		}
		else if(level = 2)
		{
			Cost = Chas_Costs[2];
		}
		else if(level =3){
			Cost = Chas_Costs[3];
		}
		else
		{
			Cost = Chas_Costs[0];
		}
	}

	if(name == "Aerodynamics")
	{
		if (level == 0)
		{
			Cost = Aero_Costs[0];
		}
		else if(level == 1)
		{
			Cost = Aero_Costs[1];
		}
		else if(level = 2)
		{
			Cost = Aero_Costs[2];
		}
		else if(level =3){
			Cost = Aero_Costs[3];
		}
		else
		{
			Cost = Aero_Costs[0];
		}
	}
	if(name == "Engine")
	{
		if (level == 0)
		{
			Cost = Eng_Costs[0];
		}
		else if(level == 1)
		{
			Cost = Eng_Costs[1];
		}
		else if(level = 2)
		{
			Cost = Eng_Costs[2];
		}
		else if(level =3){
			Cost = Eng_Costs[3];
		}
		else
		{
			Cost = Eng_Costs[0];
		}
	}

	if(name == "Electronics")
	{
		if (level == 0)
		{
			Cost = Elec_Costs[0];
		}
		else if(level == 1)
		{
			Cost = Elec_Costs[1];
		}
		else if(level = 2)
		{
			Cost = Elec_Costs[2];
		}
		else if(level =3){
			Cost = Elec_Costs[3];
		}
		else
		{
			Cost = Elec_Costs[0];
		}
	//create stats object in componenet to initialize the base
	}
}

int Component::getCost(){
	// TODO - implement Component::getCost
	return Engineering::Cost;
}

Statistics Component::getStats() {
	// TODO - implement Component::getStats
	return stats;
}

bool Component::ChangeLevel(int lvl) {
	// TODO - implement Component::ChangeLevel
	this->level = level;
}

void Component::addDepartment(Engineering* Dept)
{
}

void Component::setCost(int cost)
{
	Engineering::Cost = cost;
}