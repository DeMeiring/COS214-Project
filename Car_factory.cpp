
#include "Car_factory.h"

Engineering* Car_factory::ConstructCar() {

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

	return ChassisDept;
}
