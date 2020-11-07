#include "Engineering_Stage.h"

void Engineering_Stage::Engineering_main() {
	//Initialize Engineering Departments and their Default Values
	init();

	cout << "Welcome to the Engineering Stage of Simulation!" << endl;
	selectDepartment();
}

void Engineering_Stage::selectDepartment()
{
	//select department 
//show budget 
//iterate and pick levels to purchase
//while(true) exit if exit is typed
	cout << "Please Select a Department you would like to visit: " << endl;
	cout << getCarIterator()->CurrentComp()->getRnDName() << endl;
}

Engineering_Iterator* Engineering_Stage::getCarIterator()
{
	return car_iterator;
}


void Engineering_Stage::init()
{
	//create 4 Departments (to begin with) using addDepartment(Engineering* obj)

	Engineering *ChassisDept = new Department("Chassis", true);
	Engineering *AerodynamicsDept = new Department("Aerodynamics", true);
	Engineering *EngineDept = new Department("Engine", true);
	Engineering *ElectronicsDept = new Department("Electronics", true);

	Engineering *Suspension = new Component("Suspension", false, 1);
	Engineering *Breaks = new Component("Breaks", false, 1);
	Engineering *SurvivalShell = new Component("SurvivalShell", false, 1);

	//Aerodynamic Components
	Engineering *Diffuser = new Component("Diffuser", false, 1);//this gives 50% of the F1 cars downforce
	Engineering *FrontWing = new Component("FrontWing", false, 1);//downforce for corner control
	Engineering *RearWing = new Component("RearWing", false, 1);//downforce for traction

	//Engine Components
	Engineering *TurboCharger = new Component("TurboCharger", false, 1);//Exhaust driven turbine to drive a comnpressor to increase the density of air intake
	Engineering *WasteGate = new Component("WasteGate", false, 1);//pushes excess exhaust gas to pass by the turbine
	Engineering *DirectFuelInjection = new Component("DirectFuelInjection", false, 1);//Fuel is sprayed directly into the combustion chamber

	//Electronic Components
	Engineering *ERS = new Component("ERS", false, 1);//Harvests electrical energy from the heat and energy in the turbo and from breaks
	Engineering *ECU = new Component("ECU", false, 1);//Electronic Control Unit, Brain of the car
	Engineering *FFM = new Component("FFM", false, 1);//Fluid Flow Meter, analysis the vehicles fuel performance

	ChassisDept->addDepartment(Suspension);
	ChassisDept->addDepartment(Breaks);
	ChassisDept->addDepartment(SurvivalShell);
	ChassisDept->addDepartment(AerodynamicsDept);

	AerodynamicsDept->addDepartment(Diffuser);
	AerodynamicsDept->addDepartment(FrontWing);
	AerodynamicsDept->addDepartment(RearWing);
	AerodynamicsDept->addDepartment(EngineDept);

	EngineDept->addDepartment(TurboCharger);
	EngineDept->addDepartment(WasteGate);
	EngineDept->addDepartment(DirectFuelInjection);
	EngineDept->addDepartment(ElectronicsDept);

	ElectronicsDept->addDepartment(ERS);
	ElectronicsDept->addDepartment(ECU);
	ElectronicsDept->addDepartment(FFM);
	ElectronicsDept->addDepartment(ChassisDept);

	car_iterator = new Engineering_Iterator(ChassisDept);

	cout <<"====================================="<<endl;
	cout <<"====================================="<<endl;


	Engineering_Iterator *iterator = new Engineering_Iterator(ChassisDept);
	cout<<"Current Departments Initially 4:"<<endl;
	cout <<"-------------------------------------"<<endl;
	cout <<"-> "<<iterator->CurrentDept()->getRnDName()<< endl;


	// cout <<"-> "<< iterator->NextDept()->getRnDName()<< endl;
	// cout <<"-> "<< iterator->NextDept()->getRnDName()<< endl;
	
	cout << endl;
	cout <<"=====================================";
	cout << endl;
	cout << endl;

	int AVGlevel = 0;
	int cost = 0;
	int speed = 0;
	int acceleration = 0;
	int weight = 0;
	int handling = 0;
	int failure = 0;

	cout<<"Current Components Stats:"<<endl;
	for(int i =0;i<12;i++){
	cout <<"-------------------------------------"<<endl;
	cout << "-> " << iterator->CurrentComp()->getRnDName() << endl;
	cout <<"-------------------------------------"<<endl;
	cout <<"Cost: "<< iterator->CurrentComp()->getCost() << endl;
	cost += iterator->CurrentComp()->getCost();
	cout <<"Level: "<< iterator->CurrentComp()->getLevel()<<endl;
	AVGlevel += iterator->CurrentComp()->getLevel();
	cout <<"-------------------------------------"<<endl;
	
	cout <<"Speed: "<<iterator->CurrentComp()->getStats()->getValue("speed")<<endl;
	speed += iterator->CurrentComp()->getStats()->getValue("speed");
	cout <<"Acceleration: "<< iterator->CurrentComp()->getStats()->getValue("acceleration")<<endl;
	acceleration += iterator->CurrentComp()->getStats()->getValue("acceleration");
	cout <<"Weight: "<< iterator->CurrentComp()->getStats()->getValue("weight")<<endl;
	weight += iterator->CurrentComp()->getStats()->getValue("weight");
	cout <<"Handling: "<< iterator->CurrentComp()->getStats()->getValue("handling")<<endl;
	handling += iterator->CurrentComp()->getStats()->getValue("handling");
	cout <<"Failure: "<< iterator->CurrentComp()->getStats()->getValue("failure")<<endl;
	failure += iterator->CurrentComp()->getStats()->getValue("failure");

	if(i!=11)
	iterator->NextComp();

	}
	cout << endl;
	cout <<"=====================================";
	cout << endl;
	cout<<"The Total Stats of the Car"<<endl;
	cout<<"Speed: "<<speed<<endl;
	cout<<"Acceleration: "<<acceleration<<endl;
	cout<<"Weight: "<<weight<<endl;
	cout<<"Handling: "<<handling<<endl;
	cout<<"Failure: "<<failure<<endl;

	cout << endl;
	cout <<"=====================================";
	cout << endl;
	cout<<"The Total Stats of the Car out of 100 which we need to divide by 6 "<<endl;
	cout<<"Speed: "<<speed/6<<" or -> "<<(speed/6)*10<<"KM/H"<<endl;
	cout<<"Acceleration: "<<acceleration/6<<endl;
	cout<<"Weight: "<<weight/6<<" or -> "<<(weight/6)*10<<"KG"<<endl;
	cout<<"Handling: "<<handling/6<<" or -> "<<(handling/6)<<"%"<<endl;
	cout<<"Failure: "<<failure/6<<" or -> "<<(failure/6)<<"%"<<endl;

	cout << "-> " << iterator->NextComp()->getRnDName() << endl;
	cout << "-> " << iterator->NextComp()->getRnDName() << endl;

	cout << endl;
	cout <<"-------------------------------------"<<endl;
	cout<<"Current Components for Aerodynamics:"<<endl;
	cout <<"-------------------------------------"<<endl;
	cout << "-> " << iterator->NextComp()->getRnDName() << endl;
	cout << "-> " << iterator->NextComp()->getRnDName() << endl;
	cout << "-> " << iterator->NextComp()->getRnDName() << endl;
	
	
	cout << endl;
	cout <<"-------------------------------------"<<endl;
	cout<<"Current Components for Engine:"<<endl;
	cout <<"-------------------------------------"<<endl;
	cout << "-> " << iterator->NextComp()->getRnDName() << endl;
	cout << "-> " << iterator->NextComp()->getRnDName() << endl;
	cout << "-> " << iterator->NextComp()->getRnDName() << endl;
	
	
	cout << endl;
	cout <<"-------------------------------------"<<endl;
	cout<<"Current Components for Electronics:"<<endl;
	cout <<"-------------------------------------"<<endl;
	cout << "-> " << iterator->NextComp()->getRnDName() << endl;
	cout << "-> " << iterator->NextComp()->getRnDName() << endl;
	cout << "-> " << iterator->NextComp()->getRnDName() << endl;
	cout << "=====================================" << endl;
	cout << "=====================================" << endl;

	// cout << iterator->CurrentComp()->getCost() << endl;

	for (int i = 0; i < 3; i++)
		cout << iterator->CurrentDept()->getComponentList(ChassisDept)[i] << endl;

	cout << endl;

	for (int i = 0; i < 3; i++)
		cout << iterator->CurrentDept()->getComponentList(AerodynamicsDept)[i] << endl;
	cout << endl;

	for (int i = 0; i < 3; i++)
		cout << iterator->CurrentDept()->getComponentList(EngineDept)[i] << endl;

	cout << endl;

	for (int i = 0; i < 3; i++){
		cout << iterator->CurrentDept()->getComponentList(ElectronicsDept)[i] << endl;
	}

	cout << endl;


	cout <<iterator->CurrentComp()->getStats()->getValue("acceleration")<< endl;
	iterator->CurrentComp()->ChangeLevel(2);
	iterator->CurrentComp()->ChangeLevel(2);
	cout <<iterator->CurrentComp()->getStats()->getValue("acceleration")<< endl;


}


