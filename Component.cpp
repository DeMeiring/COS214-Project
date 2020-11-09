#include "Component.h"
Component::~Component() {

}


Component::Component(string name, bool isDept, int level) : Engineering(name, isDept)
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
	
	Engineering::level = level;
	
	if(name == "Suspension" || name == "Breaks" || name == "SurvivalShell")
	{
		if(level == 1)
		{
			Cost = Chas_Costs[1];
			Engineering::stats = new Statistics(false,false,true,false);
			Engineering::stats->ChangeValue("weight",100,false,false);
			Engineering::stats->ChangeValue("handling",20,false,false);
		}
		else
		{
			Cost = Chas_Costs[0];
			Engineering::stats = new Statistics(false,false,true,false);
			Engineering::stats->ChangeValue("weight",10000,false,false);
			Engineering::stats->ChangeValue("handling",10000,false,false);
		}
	}

	if(name == "Diffuser"||name == "FrontWing"||name == "RearWing")
	{
		if(level == 1)
		{
			Cost = Aero_Costs[1];
			Engineering::stats = new Statistics(false,false,true,false);
			Engineering::stats->ChangeValue("speed",20,false,false);//200KM/H
			Engineering::stats->ChangeValue("weight",100,false,false);
			Engineering::stats->ChangeValue("handling",20,false,false);
		}

		else
		{
			Cost = Aero_Costs[0];
			Engineering::stats = new Statistics(false,false,true,false);
			Engineering::stats->ChangeValue("speed",0,false,false);
			Engineering::stats->ChangeValue("weight",10000,false,false);
			Engineering::stats->ChangeValue("handling",0,false,false);
		}
	}
	if(name == "TurboCharger"||name=="WasteGate"||name=="DirectFuelInjection")
	{
		if(level == 1)
		{
			Cost = Eng_Costs[1];
			Engineering::stats = new Statistics(false,false,true,false);
			Engineering::stats->ChangeValue("speed",10,false,false);
			Engineering::stats->ChangeValue("acceleration",10,false,false);
			Engineering::stats->ChangeValue("failure",8,false,false);
		}
		else
		{
			Cost = Eng_Costs[0];
			Engineering::stats = new Statistics(false,false,true,false);
			Engineering::stats->ChangeValue("speed",0,false,false);
			Engineering::stats->ChangeValue("acceleration",0,false,false);
			Engineering::stats->ChangeValue("failure",10000,false,false);
		}
	}

	if(name == "ERS"||name=="ECU"||name=="FFM")
	{

		if(level == 1)
		{
			Cost = Elec_Costs[1];
			Engineering::stats = new Statistics(false,false,true,false);
			Engineering::stats->ChangeValue("acceleration",20,false,false);
			Engineering::stats->ChangeValue("failure",4,false,false);
		}
		else
		{
			Cost = Elec_Costs[0];
			Engineering::stats = new Statistics(false,false,true,false);
			Engineering::stats->ChangeValue("acceleration",0,false,false);
			Engineering::stats->ChangeValue("failure",10000,false,false);
		}
	//create stats object in component to initialize the base
	}
}

int Component::getCost(){
	// TODO - implement Component::getCost
	return Engineering::Cost;
}

bool Component::ChangeLevel(int lvl) {

	Engineering::level = lvl;
	
	if(this->getRnDName() == "Suspension" || this->getRnDName() == "Breaks" || this->getRnDName() == "SurvivalShell")
	{
		if (level == 0)
		{
			Cost = Chas_Costs[0];
			Engineering::stats = new Statistics(false,false,true,false);//initialized everything to 0 stats
			Engineering::stats->ChangeValue("weight",1000,false,false);
			Engineering::stats->ChangeValue("handling",0,false,false);
		}
		else if(level == 1)
		{
			Cost = Chas_Costs[1];
			Engineering::stats = new Statistics(false,false,true,false);
			Engineering::stats->ChangeValue("weight",100,false,false);
			Engineering::stats->ChangeValue("handling",20,false,false);
		}
		else if(level == 2)
		{
			Cost = Chas_Costs[2];
			Engineering::stats = new Statistics(false,false,true,false);
			Engineering::stats->ChangeValue("weight",70,false,false);//TODO: Ask liam if weight should be decemented or incremented
			Engineering::stats->ChangeValue("handling",60,false,false);
		}
		else if(level == 3){
			Cost = Chas_Costs[3];
			Engineering::stats = new Statistics(false,false,true,false);
			Engineering::stats->ChangeValue("weight",40,false,false);
			Engineering::stats->ChangeValue("handling",100,false,false);
		}
		else
		{
			Cost = Chas_Costs[0];
			Engineering::stats = new Statistics(false,false,true,false);
			Engineering::stats->ChangeValue("weight",10000,false,false);
			Engineering::stats->ChangeValue("handling",10000,false,false);
		}
	}

	if(this->getRnDName() == "Diffuser"||this->getRnDName() == "FrontWing"||this->getRnDName() == "RearWing")
	{
		if (level == 0)
		{
			Cost = Aero_Costs[0];
			Engineering::stats = new Statistics(false,false,true,false);
			Engineering::stats->ChangeValue("speed",0,false,false);
			Engineering::stats->ChangeValue("weight",1000,false,false);
			Engineering::stats->ChangeValue("handling",0,false,false);
		}
		else if(level == 1)
		{
			Cost = Aero_Costs[1];
			Engineering::stats = new Statistics(false,false,true,false);
			Engineering::stats->ChangeValue("speed",20,false,false);//200KM/H
			Engineering::stats->ChangeValue("weight",100,false,false);
			Engineering::stats->ChangeValue("handling",20,false,false);
		}
		else if(level == 2)
		{
			Cost = Aero_Costs[2];
			Engineering::stats = new Statistics(false,false,true,false);
			Engineering::stats->ChangeValue("speed",25,false,false);//250KM/H
			Engineering::stats->ChangeValue("weight",50,false,false);
			Engineering::stats->ChangeValue("handling",40,false,false);
		}
		else if(level ==3){
			Cost = Aero_Costs[3];
			Engineering::stats = new Statistics(false,false,true,false);
			Engineering::stats->ChangeValue("speed",35,false,false);//350KM/H
			Engineering::stats->ChangeValue("weight",20,false,false);
			Engineering::stats->ChangeValue("handling",80,false,false);
		}
		else
		{
			Cost = Aero_Costs[0];
			Engineering::stats = new Statistics(false,false,true,false);
			Engineering::stats->ChangeValue("speed",0,false,false);
			Engineering::stats->ChangeValue("weight",10000,false,false);
			Engineering::stats->ChangeValue("handling",0,false,false);
		}
	}
	if(this->getRnDName() == "TurboCharger"||this->getRnDName()=="WasteGate"||this->getRnDName()=="DirectFuelInjection")
	{
		if (level == 0)
		{
			Cost = Eng_Costs[0];
			Engineering::stats = new Statistics(false,false,true,false);
			Engineering::stats->ChangeValue("speed",0,false,false);
			Engineering::stats->ChangeValue("acceleration",0,false,false);
			Engineering::stats->ChangeValue("failure",10000,false,false);
		}
		else if(level == 1)
		{
			Cost = Eng_Costs[1];
			Engineering::stats = new Statistics(false,false,true,false);
			Engineering::stats->ChangeValue("speed",10,false,false);
			Engineering::stats->ChangeValue("acceleration",10,false,false);
			Engineering::stats->ChangeValue("failure",8,false,false);
		}
		else if(level == 2)
		{
			Cost = Eng_Costs[2];
			Engineering::stats = new Statistics(false,false,true,false);
			Engineering::stats->ChangeValue("speed",40,false,false);
			Engineering::stats->ChangeValue("acceleration",30,false,false);
			Engineering::stats->ChangeValue("failure",3,false,false);
		}
		else if(level ==3){
			Cost = Eng_Costs[3];
			Engineering::stats = new Statistics(false,false,true,false);
			Engineering::stats->ChangeValue("speed",80,false,false);
			Engineering::stats->ChangeValue("acceleration",60,false,false);
			Engineering::stats->ChangeValue("failure",1,false,false);
		}
		else
		{
			Cost = Eng_Costs[0];
			Engineering::stats = new Statistics(false,false,true,false);
			Engineering::stats->ChangeValue("speed",0,false,false);
			Engineering::stats->ChangeValue("acceleration",0,false,false);
			Engineering::stats->ChangeValue("failure",10000,false,false);
		}
	}

	if(this->getRnDName() == "ERS"||this->getRnDName()=="ECU"||this->getRnDName()=="FFM")
	{
		if (level == 0)
		{
			Cost = Elec_Costs[0];
			Engineering::stats = new Statistics(false,false,true,false);
			Engineering::stats->ChangeValue("acceleration",0,false,false);
			Engineering::stats->ChangeValue("failure",10000,false,false);
		}
		else if(level == 1)
		{
			Cost = Elec_Costs[1];
			Engineering::stats = new Statistics(false,false,true,false);
			Engineering::stats->ChangeValue("acceleration",20,false,false);
			Engineering::stats->ChangeValue("failure",4,false,false);
		}
		else if(level == 2)
		{
			Cost = Elec_Costs[2];
			Engineering::stats = new Statistics(false,false,true,false);
			Engineering::stats->ChangeValue("acceleration",50,false,false);
			Engineering::stats->ChangeValue("failure",2,false,false);
		}
		else if(level ==3){
			Cost = Elec_Costs[3];
			Engineering::stats = new Statistics(false,false,true,false);
			Engineering::stats->ChangeValue("acceleration",80,false,false);
			Engineering::stats->ChangeValue("failure",1,false,false);
		}
		else
		{
			Cost = Elec_Costs[0];
			Engineering::stats = new Statistics(false,false,true,false);
			Engineering::stats->ChangeValue("acceleration",0,false,false);
			Engineering::stats->ChangeValue("failure",10000,false,false);
		}
	//create stats object in componenet to initialize the base
	}
	return true;
}

void Component::addDepartment(Engineering* Dept)
{
}

vector<string> Component::getComponentList(Engineering *Dept)
{
	vector<string> list;
	return list;
}

void Component::setCost(int cost)
{
	Engineering::Cost = cost;
}
