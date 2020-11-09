#include "Opposing_Car.h"

Opposing_Car::~Opposing_Car() {}

// implement when Joseph and Dean finish engineering
Engineering* Opposing_Car::GenCar(int dif) {

    Statistics *stats = new Statistics(false, true);
    int rando;

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

    if(dif > 90) {
        Suspension->ChangeLevel(3);
        Breaks->ChangeLevel(3);
        SurvivalShell->ChangeLevel(3);
        Diffuser->ChangeLevel(3);
        FrontWing->ChangeLevel(3);
        RearWing->ChangeLevel(3);
        TurboCharger->ChangeLevel(3);
        WasteGate->ChangeLevel(3);
        DirectFuelInjection->ChangeLevel(3);
        ERS->ChangeLevel(3);
        ECU->ChangeLevel(3);
        FFM->ChangeLevel(3);
    }
    else if(dif > 80 && dif < 90 ) {
        Suspension->ChangeLevel(3);
        Breaks->ChangeLevel(2);
        SurvivalShell->ChangeLevel(2);
        Diffuser->ChangeLevel(3);
        FrontWing->ChangeLevel(2);
        RearWing->ChangeLevel(3);
        TurboCharger->ChangeLevel(3);
        WasteGate->ChangeLevel(3);
        DirectFuelInjection->ChangeLevel(2);
        ERS->ChangeLevel(3);
        ECU->ChangeLevel(2);
        FFM->ChangeLevel(3);
    }
    else if(dif > 70 && dif < 80 ) {
        Suspension->ChangeLevel(2);
        Breaks->ChangeLevel(2);
        SurvivalShell->ChangeLevel(2);
        Diffuser->ChangeLevel(2);
        FrontWing->ChangeLevel(3);
        RearWing->ChangeLevel(2);
        TurboCharger->ChangeLevel(3);
        WasteGate->ChangeLevel(2);
        DirectFuelInjection->ChangeLevel(2);
        ERS->ChangeLevel(2);
        ECU->ChangeLevel(2);
        FFM->ChangeLevel(2);
    }
    else if(dif > 60 && dif < 70 ) {
        Suspension->ChangeLevel(2);
        Breaks->ChangeLevel(2);
        SurvivalShell->ChangeLevel(2);
        Diffuser->ChangeLevel(2);
        FrontWing->ChangeLevel(2);
        RearWing->ChangeLevel(2);
        TurboCharger->ChangeLevel(2);
        WasteGate->ChangeLevel(2);
        DirectFuelInjection->ChangeLevel(2);
        ERS->ChangeLevel(2);
        ECU->ChangeLevel(2);
        FFM->ChangeLevel(2);
    }
    else {
        Suspension->ChangeLevel(1);
        Breaks->ChangeLevel(1);
        SurvivalShell->ChangeLevel(1);
        Diffuser->ChangeLevel(1);
        FrontWing->ChangeLevel(2);
        RearWing->ChangeLevel(2);
        TurboCharger->ChangeLevel(1);
        WasteGate->ChangeLevel(1);
        DirectFuelInjection->ChangeLevel(1);
        ERS->ChangeLevel(1);
        ECU->ChangeLevel(1);
        FFM->ChangeLevel(2);
    }

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