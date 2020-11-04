#include "Engineering_Stage.h"

void Engineering_Stage::Engineering_main() {
	// TODO - implement Engineering_Stage::Engineering_main
	init();
	
}

void Engineering_Stage::init()
{
	//create 4 Departments (to begin with) using addDepartment(Engineering* obj)

	Engineering *ChassisDept = new Department("Body", true);
	Engineering *AerodynamicsDept = new Department("Aerodynamics", true);
	Engineering *EngineDept = new Department("Engine", true);
	Engineering *ElectronicsDept = new Department("Electronics", true);

	Engineering *Suspension = new Component("Suspension", false);
	Engineering *Breaks = new Component("Breaks", false);
	Engineering *SurvivalShell = new Component("Component", false);


	//Aerodynamic Components
	Engineering *Diffuser = new Component("Diffuser", false);//this gives 50% of the F1 cars downforce
	Engineering *FrontWing = new Component("FrontWing", false);//downforce for corner control
	Engineering *RearWing = new Component("RearWing", false);//downforce for traction

	//Engine Components
	Engineering *TurboCharger = new Component("TurboCharger", false);//Exhaust driven turbine to drive a comnpressor to increase the density of air intake
	Engineering *WasteGate = new Component("WasteGate", false);//pushes excess exhaust gas to pass by the turbine
	Engineering *DirectFuelInjection = new Component("DirectFuelInjection", false);//Fuel is sprayed directly into the combustion chamber

	//Electronic Components
	Engineering *ERS = new Component("ERS", false);//Harvests electrical energy from the heat and energy in the turbo and from breaks
	Engineering *ECU = new Component("ECU", false);//Electronic Control Unit, Brain of the car
	Engineering *FFM = new Component("FFM", false);//Fluid Flow Meter, analysis the vehicles fuel performance

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
}
