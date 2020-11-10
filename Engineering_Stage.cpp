#include "Engineering_Stage.h"
#include "Client.h"

Engineering_Stage::Engineering_Stage(Client* cl) : Stage(cl) {
    init();
}

Stage* Engineering_Stage::ChangeStage(int Stage) {
     Stage::getClient()->SetStage(Stage::getClient()->getStages()[1]);
     return 0;
}

void Engineering_Stage::RunStage() {
    Engineering_main();
    Stage::getClient()->SetStage(Stage::getClient()->getStages()[1]);
}
Engineering_Stage::~Engineering_Stage()
{

}

void Engineering_Stage::Engineering_main() {
	//Initialize Engineering Departments and their Default Values
	init();
	system("clear");
	cout << endl;
	
cout<<"########################################################################"<<endl;
cout<<"#                                                                      #"<<endl;  
cout<<"#        _            /'_'_/.-''/                             _______  #"<<endl;
cout<<"#  <`../ |o_..__     / /__   / /  -= ENGINEERING STAGE =-   _<=.o.=>_  #"<<endl;
cout<<"#`.,(_)______(_).>  / ___/  / /                             |_|_____|_|#"<<endl;
cout<<"#~~~~~~~~~~~~~~~~~~/_/~~~~~/_/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#"<<endl;						                                           
cout<<"########################################################################"<<endl;
cout<<endl;
cout<<"           Welcome to the Engineering Stage of Simulation!" << endl;
cout<<"           ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~            " << endl;

	Car = selectDepartment();
	A_Base_Car *createdCar = new A_Base_Car();
	
	Transport *transport = new Transport();
	transport->AddCar(createdCar->CreateBluePrint(Car));

	createdCar->RestoreCar(transport->RemoveCar());

}

Engineering* Engineering_Stage::selectDepartment()
{
	//select department 
//show budget 
//iterate and pick levels to purchase
//while(true) exit if exit is typed
int choice2;	
	string convertedCost;
	int_fast64_t decision;
	string tooExpensive = "You cannot afford this upgrade";

	cout << endl;
	cout<<"------------------------------------------------------------------------" << endl;
	cout << "Please Select a Department you would like to visit: " << endl;
	
	cout << "1. Chassis Department" << endl;
	cout << "2. Aerodynamics Department" << endl;
	cout << "3. Engine Department" << endl;
	cout << "4. Electronics Department" << endl;
	cout << "5. Return To Main Program" << endl;
	cin >> decision;

	switch(decision){ //select the department
		case 1:
			car_iterator->resetCurrComp();
			system("clear");
			cout << endl;
			cout<<"========================================================================" << endl;
			cout << "Chassis Department: " << endl;
			cout<<"========================================================================" << endl << endl;
			
			cout << "Current Budget: $" << convertCost(getBudget()) << endl <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl <<endl;
			cout << "Current Component Levels: " << endl;
			cout<<"------------------------------------------------------------------------" << endl;
			for(int i = 0; i < 3; i++)
			{
				cout << car_iterator->CurrentComp()->getRnDName() << ": Level " << car_iterator->CurrentComp()->getLevel() << endl;
				car_iterator->NextComp();
			}
			car_iterator->resetCurrComp();
			cout<<"------------------------------------------------------------------------" << endl;
			cout << endl << "Which Component would you like to upgrade?" << endl;
			cout << "1. Suspension" << endl;
			cout << "2. Breaks" << endl;
			cout << "3. SurvivalShell" << endl;
			
			cin >> choice2;
			switch(choice2) //select the component
			{
				case 1:
					car_iterator->CurrentComp()->ChangeLevel(2);
					convertedCost = convertCost(car_iterator->CurrentComp()->getCost());
					cout << "1. Upgrade to Level 2  ($"<< convertedCost << ")" << endl;
					car_iterator->CurrentComp()->ChangeLevel(3);
					convertedCost = convertCost(car_iterator->CurrentComp()->getCost());
					cout << "2. Upgrade to Level 3  ($" << convertedCost << ")" << endl;
					car_iterator->CurrentComp()->ChangeLevel(1);

					cout << endl;
					
					cin >> choice3;
					switch(choice3){ //select the level
						case 1: //upgrade to Level 2
							//first need to verify if currentBudget() will allow for upgrade. 
						
						if(car_iterator->CurrentComp()->getLevel() == 2){
							cout << "This Component is already Level 2" << endl;
						}
						else{
							car_iterator->CurrentComp()->ChangeLevel(2);
							if(car_iterator->CurrentComp()->getCost() > getBudget())
							{
								cout << tooExpensive << endl;
								car_iterator->CurrentComp()->ChangeLevel(1);
							}
							setBudget(getBudget() - car_iterator->CurrentComp()->getCost());
							cout << "Budget Remaining: $" << convertCost(getBudget()) << endl;
							
						}
						selectDepartment();
						
						case 2://upgrade to Level 3
							if(car_iterator->CurrentComp()->getLevel() == 3)
							{
								cout << "This Component is already level 3" << endl;
								selectDepartment();
							}
							else if(car_iterator->CurrentComp()->getLevel() == 1)
							{
								car_iterator->CurrentComp()->ChangeLevel(3);
								if(car_iterator->CurrentComp()->getCost() > getBudget())
								{
									cout << tooExpensive << endl;
									car_iterator->CurrentComp()->ChangeLevel(1);
								}
								
							}
							else if(car_iterator->CurrentComp()->getLevel() == 2){
								car_iterator->CurrentComp()->ChangeLevel(3);
								if(car_iterator->CurrentComp()->getCost() > getBudget())
								{
									cout << tooExpensive << endl;
									car_iterator->CurrentComp()->ChangeLevel(2);
								}
							}
							if(car_iterator->CurrentComp()->getCost() < getBudget()){
							setBudget(getBudget() - car_iterator->CurrentComp()->getCost());
							}
							cout << "Budget Remaining: $" << convertCost(getBudget()) << endl;
							
					
					selectDepartment();
					

					default:
						selectDepartment();
					}
				case 2: //Breaks;
					car_iterator->resetCurrComp();
					car_iterator->NextComp();
					car_iterator->CurrentComp()->ChangeLevel(2);
					convertedCost = convertCost(car_iterator->CurrentComp()->getCost());
					cout << "1. Upgrade to Level 2  ($"<< convertedCost << ")" << endl;
					car_iterator->CurrentComp()->ChangeLevel(3);
					convertedCost = convertCost(car_iterator->CurrentComp()->getCost());
					cout << "2. Upgrade to Level 3  ($" << convertedCost << ")" << endl;
					car_iterator->CurrentComp()->ChangeLevel(1);

					cout << endl;
					
					cin >> choice3;
					switch(choice3){ //select the level
						case 1: //upgrade to Level 2
							//first need to verify if currentBudget() will allow for upgrade. 
						
						if(car_iterator->CurrentComp()->getLevel() == 2){
							cout << "This Component is already Level 2" << endl;
						}
						else{
							car_iterator->CurrentComp()->ChangeLevel(2);
							if(car_iterator->CurrentComp()->getCost() > getBudget())
							{
								cout << tooExpensive << endl;
								car_iterator->CurrentComp()->ChangeLevel(1);
							}
							setBudget(getBudget() - car_iterator->CurrentComp()->getCost());
							cout << "Budget Remaining: $" << convertCost(getBudget()) << endl;
							
						}
						selectDepartment();
						
						case 2://upgrade to Level 3
							if(car_iterator->CurrentComp()->getLevel() == 3)
							{
								cout << "This Component is already level 3" << endl;
								selectDepartment();
							}
							else if(car_iterator->CurrentComp()->getLevel() == 1)
							{
								car_iterator->CurrentComp()->ChangeLevel(3);
								if(car_iterator->CurrentComp()->getCost() > getBudget())
								{
									cout << tooExpensive << endl;
									car_iterator->CurrentComp()->ChangeLevel(1);
								}
								
							}
							else if(car_iterator->CurrentComp()->getLevel() == 2){
								car_iterator->CurrentComp()->ChangeLevel(3);
								if(car_iterator->CurrentComp()->getCost() > getBudget())
								{
									cout << tooExpensive << endl;
									car_iterator->CurrentComp()->ChangeLevel(2);
								}
							}
							if(car_iterator->CurrentComp()->getCost() < getBudget()){
							setBudget(getBudget() - car_iterator->CurrentComp()->getCost());
							}
							cout << "Budget Remaining: $" << convertCost(getBudget()) << endl;
							
					
					selectDepartment();
					

					default:
						selectDepartment();
					}
					case 3: //SurvivalShell;
					car_iterator->resetCurrComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->CurrentComp()->ChangeLevel(2);
					convertedCost = convertCost(car_iterator->CurrentComp()->getCost());
					cout << "1. Upgrade to Level 2  ($"<< convertedCost << ")" << endl;
					car_iterator->CurrentComp()->ChangeLevel(3);
					convertedCost = convertCost(car_iterator->CurrentComp()->getCost());
					cout << "2. Upgrade to Level 3  ($" << convertedCost << ")" << endl;
					car_iterator->CurrentComp()->ChangeLevel(1);

					cout << endl;
					
					cin >> choice3;
					switch(choice3){ //select the level
						case 1: //upgrade to Level 2
							//first need to verify if currentBudget() will allow for upgrade. 
						
						if(car_iterator->CurrentComp()->getLevel() == 2){
							cout << "This Component is already Level 2" << endl;
						}
						else{
							car_iterator->CurrentComp()->ChangeLevel(2);
							if(car_iterator->CurrentComp()->getCost() > getBudget())
							{
								cout << tooExpensive << endl;
								car_iterator->CurrentComp()->ChangeLevel(1);
							}
							setBudget(getBudget() - car_iterator->CurrentComp()->getCost());
							cout << "Budget Remaining: $" << convertCost(getBudget()) << endl;
							
						}
						selectDepartment();
						
						case 2://upgrade to Level 3
							if(car_iterator->CurrentComp()->getLevel() == 3)
							{
								cout << "This Component is already level 3" << endl;
								selectDepartment();
							}
							else if(car_iterator->CurrentComp()->getLevel() == 1)
							{
								car_iterator->CurrentComp()->ChangeLevel(3);
								if(car_iterator->CurrentComp()->getCost() > getBudget())
								{
									cout << tooExpensive << endl;
									car_iterator->CurrentComp()->ChangeLevel(1);
								}
								
							}
							else if(car_iterator->CurrentComp()->getLevel() == 2){
								car_iterator->CurrentComp()->ChangeLevel(3);
								if(car_iterator->CurrentComp()->getCost() > getBudget())
								{
									cout << tooExpensive << endl;
									car_iterator->CurrentComp()->ChangeLevel(2);
								}
							}
							if(car_iterator->CurrentComp()->getCost() < getBudget()){
							setBudget(getBudget() - car_iterator->CurrentComp()->getCost());
							}
							cout << "Budget Remaining: $" << convertCost(getBudget()) << endl;
							
					
					selectDepartment();
					

					default:
						selectDepartment();
					}
				}

		case 2:
			system("clear");
			cout << endl;
			cout << "========================================================================" << endl;
			cout << "Aerodynamics Department: " << endl;
			cout << "========================================================================" << endl
				 << endl;

			cout << "Current Budget: $" << convertCost(getBudget()) << endl
				 << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
				 << endl;
			cout << "Current Component Levels: " << endl;
			cout << "------------------------------------------------------------------------" << endl;
			car_iterator->resetCurrComp();
			car_iterator->NextComp();
			car_iterator->NextComp();
			car_iterator->NextComp();
			for (int i = 0; i < 3; i++)
			{
				cout << car_iterator->CurrentComp()->getRnDName() << ": Level " << car_iterator->CurrentComp()->getLevel() << endl;
				car_iterator->NextComp();
			}
			car_iterator->resetCurrComp();
			cout<<"------------------------------------------------------------------------" << endl;
			cout << endl << "Which Component would you like to upgrade?" << endl;
			cout << "1. Diffuser" << endl;
			cout << "2. Front Wing" << endl;
			cout << "3. Rear Wing" << endl;
			
			
			cin >> choice2;
			switch(choice2) //select the component
			{
				case 1:
					car_iterator->resetCurrComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();

					car_iterator->CurrentComp()->ChangeLevel(2);
					convertedCost = convertCost(car_iterator->CurrentComp()->getCost());
					cout << "1. Upgrade to Level 2  ($"<< convertedCost << ")" << endl;
					car_iterator->CurrentComp()->ChangeLevel(3);
					convertedCost = convertCost(car_iterator->CurrentComp()->getCost());
					cout << "2. Upgrade to Level 3  ($" << convertedCost << ")" << endl;
					car_iterator->CurrentComp()->ChangeLevel(1);

					cout << endl;
					
					cin >> choice3;
					switch(choice3){ //select the level
						case 1: //upgrade to Level 2
							//first need to verify if currentBudget() will allow for upgrade. 
						
						if(car_iterator->CurrentComp()->getLevel() == 2){
							cout << "This Component is already Level 2" << endl;
						}
						else{
							car_iterator->CurrentComp()->ChangeLevel(2);
							if(car_iterator->CurrentComp()->getCost() > getBudget())
							{
								cout << tooExpensive << endl;
								car_iterator->CurrentComp()->ChangeLevel(1);
							}
							setBudget(getBudget() - car_iterator->CurrentComp()->getCost());
							cout << "Budget Remaining: $" << convertCost(getBudget()) << endl;
							
						}
						selectDepartment();
						
						case 2://upgrade to Level 3
							if(car_iterator->CurrentComp()->getLevel() == 3)
							{
								cout << "This Component is already level 3" << endl;
								selectDepartment();
							}
							else if(car_iterator->CurrentComp()->getLevel() == 1)
							{
								car_iterator->CurrentComp()->ChangeLevel(3);
								if(car_iterator->CurrentComp()->getCost() > getBudget())
								{
									cout << tooExpensive << endl;
									car_iterator->CurrentComp()->ChangeLevel(1);
								}
								
							}
							else if(car_iterator->CurrentComp()->getLevel() == 2){
								car_iterator->CurrentComp()->ChangeLevel(3);
								if(car_iterator->CurrentComp()->getCost() > getBudget())
								{
									cout << tooExpensive << endl;
									car_iterator->CurrentComp()->ChangeLevel(2);
								}
							}
							if(car_iterator->CurrentComp()->getCost() < getBudget()){
							setBudget(getBudget() - car_iterator->CurrentComp()->getCost());
							}
							cout << "Budget Remaining: $" << convertCost(getBudget()) << endl;
							
					
					selectDepartment();
					

					default:
						selectDepartment();
					}
				case 2: //Breaks;
					car_iterator->resetCurrComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
				
					car_iterator->CurrentComp()->ChangeLevel(2);
					convertedCost = convertCost(car_iterator->CurrentComp()->getCost());
					cout << "1. Upgrade to Level 2  ($"<< convertedCost << ")" << endl;
					car_iterator->CurrentComp()->ChangeLevel(3);
					convertedCost = convertCost(car_iterator->CurrentComp()->getCost());
					cout << "2. Upgrade to Level 3  ($" << convertedCost << ")" << endl;
					car_iterator->CurrentComp()->ChangeLevel(1);

					cout << endl;
					
					cin >> choice3;
					switch(choice3){ //select the level
						case 1: //upgrade to Level 2
							//first need to verify if currentBudget() will allow for upgrade. 
						
						if(car_iterator->CurrentComp()->getLevel() == 2){
							cout << "This Component is already Level 2" << endl;
						}
						else{
							car_iterator->CurrentComp()->ChangeLevel(2);
							if(car_iterator->CurrentComp()->getCost() > getBudget())
							{
								cout << tooExpensive << endl;
								car_iterator->CurrentComp()->ChangeLevel(1);
							}
							setBudget(getBudget() - car_iterator->CurrentComp()->getCost());
							cout << "Budget Remaining: $" << convertCost(getBudget()) << endl;
							
						}
						selectDepartment();
						
						case 2://upgrade to Level 3
							if(car_iterator->CurrentComp()->getLevel() == 3)
							{
								cout << "This Component is already level 3" << endl;
								selectDepartment();
							}
							else if(car_iterator->CurrentComp()->getLevel() == 1)
							{
								car_iterator->CurrentComp()->ChangeLevel(3);
								if(car_iterator->CurrentComp()->getCost() > getBudget())
								{
									cout << tooExpensive << endl;
									car_iterator->CurrentComp()->ChangeLevel(1);
								}
								
							}
							else if(car_iterator->CurrentComp()->getLevel() == 2){
								car_iterator->CurrentComp()->ChangeLevel(3);
								if(car_iterator->CurrentComp()->getCost() > getBudget())
								{
									cout << tooExpensive << endl;
									car_iterator->CurrentComp()->ChangeLevel(2);
								}
							}
							if(car_iterator->CurrentComp()->getCost() < getBudget()){
							setBudget(getBudget() - car_iterator->CurrentComp()->getCost());
							}
							cout << "Budget Remaining: $" << convertCost(getBudget()) << endl;
							
					
					selectDepartment();
					

					default:
						selectDepartment();
					}
					case 3: //SurvivalShell;
					car_iterator->resetCurrComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->CurrentComp()->ChangeLevel(2);
					convertedCost = convertCost(car_iterator->CurrentComp()->getCost());
					cout << "1. Upgrade to Level 2  ($"<< convertedCost << ")" << endl;
					car_iterator->CurrentComp()->ChangeLevel(3);
					convertedCost = convertCost(car_iterator->CurrentComp()->getCost());
					cout << "2. Upgrade to Level 3  ($" << convertedCost << ")" << endl;
					car_iterator->CurrentComp()->ChangeLevel(1);

					cout << endl;
					
					cin >> choice3;
					switch(choice3){ //select the level
						case 1: //upgrade to Level 2
							//first need to verify if currentBudget() will allow for upgrade. 
						
						if(car_iterator->CurrentComp()->getLevel() == 2){
							cout << "This Component is already Level 2" << endl;
						}
						else{
							car_iterator->CurrentComp()->ChangeLevel(2);
							if(car_iterator->CurrentComp()->getCost() > getBudget())
							{
								cout << tooExpensive << endl;
								car_iterator->CurrentComp()->ChangeLevel(1);
							}
							setBudget(getBudget() - car_iterator->CurrentComp()->getCost());
							cout << "Budget Remaining: $" << convertCost(getBudget()) << endl;
							
						}
						selectDepartment();
						
						case 2://upgrade to Level 3
							if(car_iterator->CurrentComp()->getLevel() == 3)
							{
								cout << "This Component is already level 3" << endl;
								selectDepartment();
							}
							else if(car_iterator->CurrentComp()->getLevel() == 1)
							{
								car_iterator->CurrentComp()->ChangeLevel(3);
								if(car_iterator->CurrentComp()->getCost() > getBudget())
								{
									cout << tooExpensive << endl;
									car_iterator->CurrentComp()->ChangeLevel(1);
								}
								
							}
							else if(car_iterator->CurrentComp()->getLevel() == 2){
								car_iterator->CurrentComp()->ChangeLevel(3);
								if(car_iterator->CurrentComp()->getCost() > getBudget())
								{
									cout << tooExpensive << endl;
									car_iterator->CurrentComp()->ChangeLevel(2);
								}
							}
							if(car_iterator->CurrentComp()->getCost() < getBudget()){
							setBudget(getBudget() - car_iterator->CurrentComp()->getCost());
							}
							cout << "Budget Remaining: $" << convertCost(getBudget()) << endl;
							
					
					selectDepartment();
					

					default:
						selectDepartment();
					}
			}
		case 3:
		system("clear");
			cout << endl;
			cout << "========================================================================" << endl;
			cout << "Engine Department: " << endl;
			cout << "========================================================================" << endl
				 << endl;

			cout << "Current Budget: $" << convertCost(getBudget()) << endl
				 << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
				 << endl;
			cout << "Current Component Levels: " << endl;
			cout << "------------------------------------------------------------------------" << endl;
			car_iterator->resetCurrComp();
			car_iterator->NextComp();
			car_iterator->NextComp();
			car_iterator->NextComp();
			car_iterator->NextComp();
			car_iterator->NextComp();
			car_iterator->NextComp();
			for (int i = 0; i < 3; i++)
			{
				cout << car_iterator->CurrentComp()->getRnDName() << ": Level " << car_iterator->CurrentComp()->getLevel() << endl;
				car_iterator->NextComp();
			}
			car_iterator->resetCurrComp();
			cout<<"------------------------------------------------------------------------" << endl;
			cout << endl << "Which Component would you like to upgrade?" << endl;
			cout << "1. Turbo Charger" << endl;
			cout << "2. Waste Gate" << endl;
			cout << "3. Direct Fuel Injection" << endl;
			
			
			cin >> choice2;
			switch(choice2) //select the component
			{
				case 1:
					car_iterator->resetCurrComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();

					car_iterator->CurrentComp()->ChangeLevel(2);
					convertedCost = convertCost(car_iterator->CurrentComp()->getCost());
					cout << "1. Upgrade to Level 2  ($"<< convertedCost << ")" << endl;
					car_iterator->CurrentComp()->ChangeLevel(3);
					convertedCost = convertCost(car_iterator->CurrentComp()->getCost());
					cout << "2. Upgrade to Level 3  ($" << convertedCost << ")" << endl;
					car_iterator->CurrentComp()->ChangeLevel(1);

					cout << endl;
					
					cin >> choice3;
					switch(choice3){ //select the level
						case 1: //upgrade to Level 2
							//first need to verify if currentBudget() will allow for upgrade. 
						
						if(car_iterator->CurrentComp()->getLevel() == 2){
							cout << "This Component is already Level 2" << endl;
						}
						else{
							car_iterator->CurrentComp()->ChangeLevel(2);
							if(car_iterator->CurrentComp()->getCost() > getBudget())
							{
								cout << tooExpensive << endl;
								car_iterator->CurrentComp()->ChangeLevel(1);
							}
							setBudget(getBudget() - car_iterator->CurrentComp()->getCost());
							cout << "Budget Remaining: $" << convertCost(getBudget()) << endl;
							
						}
						selectDepartment();
						
						case 2://upgrade to Level 3
							if(car_iterator->CurrentComp()->getLevel() == 3)
							{
								cout << "This Component is already level 3" << endl;
								selectDepartment();
							}
							else if(car_iterator->CurrentComp()->getLevel() == 1)
							{
								car_iterator->CurrentComp()->ChangeLevel(3);
								if(car_iterator->CurrentComp()->getCost() > getBudget())
								{
									cout << tooExpensive << endl;
									car_iterator->CurrentComp()->ChangeLevel(1);
								}
								
							}
							else if(car_iterator->CurrentComp()->getLevel() == 2){
								car_iterator->CurrentComp()->ChangeLevel(3);
								if(car_iterator->CurrentComp()->getCost() > getBudget())
								{
									cout << tooExpensive << endl;
									car_iterator->CurrentComp()->ChangeLevel(2);
								}
							}
							if(car_iterator->CurrentComp()->getCost() < getBudget()){
							setBudget(getBudget() - car_iterator->CurrentComp()->getCost());
							}
							cout << "Budget Remaining: $" << convertCost(getBudget()) << endl;
							
					
					selectDepartment();
					

					default:
						selectDepartment();
					}
				case 2: //Breaks;
					car_iterator->resetCurrComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
				
					car_iterator->CurrentComp()->ChangeLevel(2);
					convertedCost = convertCost(car_iterator->CurrentComp()->getCost());
					cout << "1. Upgrade to Level 2  ($"<< convertedCost << ")" << endl;
					car_iterator->CurrentComp()->ChangeLevel(3);
					convertedCost = convertCost(car_iterator->CurrentComp()->getCost());
					cout << "2. Upgrade to Level 3  ($" << convertedCost << ")" << endl;
					car_iterator->CurrentComp()->ChangeLevel(1);

					cout << endl;
					
					cin >> choice3;
					switch(choice3){ //select the level
						case 1: //upgrade to Level 2
							//first need to verify if currentBudget() will allow for upgrade. 
						
						if(car_iterator->CurrentComp()->getLevel() == 2){
							cout << "This Component is already Level 2" << endl;
						}
						else{
							car_iterator->CurrentComp()->ChangeLevel(2);
							if(car_iterator->CurrentComp()->getCost() > getBudget())
							{
								cout << tooExpensive << endl;
								car_iterator->CurrentComp()->ChangeLevel(1);
							}
							setBudget(getBudget() - car_iterator->CurrentComp()->getCost());
							cout << "Budget Remaining: $" << convertCost(getBudget()) << endl;
							
						}
						selectDepartment();
						
						case 2://upgrade to Level 3
							if(car_iterator->CurrentComp()->getLevel() == 3)
							{
								cout << "This Component is already level 3" << endl;
								selectDepartment();
							}
							else if(car_iterator->CurrentComp()->getLevel() == 1)
							{
								car_iterator->CurrentComp()->ChangeLevel(3);
								if(car_iterator->CurrentComp()->getCost() > getBudget())
								{
									cout << tooExpensive << endl;
									car_iterator->CurrentComp()->ChangeLevel(1);
								}
								
							}
							else if(car_iterator->CurrentComp()->getLevel() == 2){
								car_iterator->CurrentComp()->ChangeLevel(3);
								if(car_iterator->CurrentComp()->getCost() > getBudget())
								{
									cout << tooExpensive << endl;
									car_iterator->CurrentComp()->ChangeLevel(2);
								}
							}
							if(car_iterator->CurrentComp()->getCost() < getBudget()){
							setBudget(getBudget() - car_iterator->CurrentComp()->getCost());
							}
							cout << "Budget Remaining: $" << convertCost(getBudget()) << endl;
							
					
					selectDepartment();
					

					default:
						selectDepartment();
					}
					case 3: //SurvivalShell;
					car_iterator->resetCurrComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();

					car_iterator->CurrentComp()->ChangeLevel(2);
					convertedCost = convertCost(car_iterator->CurrentComp()->getCost());
					cout << "1. Upgrade to Level 2  ($"<< convertedCost << ")" << endl;
					car_iterator->CurrentComp()->ChangeLevel(3);
					convertedCost = convertCost(car_iterator->CurrentComp()->getCost());
					cout << "2. Upgrade to Level 3  ($" << convertedCost << ")" << endl;
					car_iterator->CurrentComp()->ChangeLevel(1);

					cout << endl;
					
					cin >> choice3;
					switch(choice3){ //select the level
						case 1: //upgrade to Level 2
							//first need to verify if currentBudget() will allow for upgrade. 
						
						if(car_iterator->CurrentComp()->getLevel() == 2){
							cout << "This Component is already Level 2" << endl;
						}
						else{
							car_iterator->CurrentComp()->ChangeLevel(2);
							if(car_iterator->CurrentComp()->getCost() > getBudget())
							{
								cout << tooExpensive << endl;
								car_iterator->CurrentComp()->ChangeLevel(1);
							}
							setBudget(getBudget() - car_iterator->CurrentComp()->getCost());
							cout << "Budget Remaining: $" << convertCost(getBudget()) << endl;
							
						}
						selectDepartment();
						
						case 2://upgrade to Level 3
							if(car_iterator->CurrentComp()->getLevel() == 3)
							{
								cout << "This Component is already level 3" << endl;
								selectDepartment();
							}
							else if(car_iterator->CurrentComp()->getLevel() == 1)
							{
								car_iterator->CurrentComp()->ChangeLevel(3);
								if(car_iterator->CurrentComp()->getCost() > getBudget())
								{
									cout << tooExpensive << endl;
									car_iterator->CurrentComp()->ChangeLevel(1);
								}
								
							}
							else if(car_iterator->CurrentComp()->getLevel() == 2){
								car_iterator->CurrentComp()->ChangeLevel(3);
								if(car_iterator->CurrentComp()->getCost() > getBudget())
								{
									cout << tooExpensive << endl;
									car_iterator->CurrentComp()->ChangeLevel(2);
								}
							}
							if(car_iterator->CurrentComp()->getCost() < getBudget()){
							setBudget(getBudget() - car_iterator->CurrentComp()->getCost());
							}
							cout << "Budget Remaining: $" << convertCost(getBudget()) << endl;
							
					
					selectDepartment();
					

					default:
						selectDepartment();
					}
			}

		case 4:
		system("clear");
			cout << endl;
			cout << "========================================================================" << endl;
			cout << "Electronics Department: " << endl;
			cout << "========================================================================" << endl
				 << endl;

			cout << "Current Budget: $" << convertCost(getBudget()) << endl
				 << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
				 << endl;
			cout << "Current Component Levels: " << endl;
			cout << "------------------------------------------------------------------------" << endl;
			car_iterator->resetCurrComp();
			car_iterator->NextComp();
			car_iterator->NextComp();
			car_iterator->NextComp();
			car_iterator->NextComp();
			car_iterator->NextComp();
			car_iterator->NextComp();
			car_iterator->NextComp();
			car_iterator->NextComp();
			car_iterator->NextComp();
			for (int i = 0; i < 3; i++)
			{
				cout << car_iterator->CurrentComp()->getRnDName() << ": Level " << car_iterator->CurrentComp()->getLevel() << endl;
				car_iterator->NextComp();
			}
			car_iterator->resetCurrComp();
			cout<<"------------------------------------------------------------------------" << endl;
			cout << endl << "Which Component would you like to upgrade?" << endl;
			cout << "1. ERS" << endl;
			cout << "2. ECU" << endl;
			cout << "3. FFM" << endl;
			
			
			cin >> choice2;
			switch(choice2) //select the component
			{
				case 1:
					car_iterator->resetCurrComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();

					car_iterator->CurrentComp()->ChangeLevel(2);
					convertedCost = convertCost(car_iterator->CurrentComp()->getCost());
					cout << "1. Upgrade to Level 2  ($"<< convertedCost << ")" << endl;
					car_iterator->CurrentComp()->ChangeLevel(3);
					convertedCost = convertCost(car_iterator->CurrentComp()->getCost());
					cout << "2. Upgrade to Level 3  ($" << convertedCost << ")" << endl;
					car_iterator->CurrentComp()->ChangeLevel(1);

					cout << endl;
					
					cin >> choice3;
					switch(choice3){ //select the level
						case 1: //upgrade to Level 2
							//first need to verify if currentBudget() will allow for upgrade. 
						
						if(car_iterator->CurrentComp()->getLevel() == 2){
							cout << "This Component is already Level 2" << endl;
						}
						else{
							car_iterator->CurrentComp()->ChangeLevel(2);
							if(car_iterator->CurrentComp()->getCost() > getBudget())
							{
								cout << tooExpensive << endl;
								car_iterator->CurrentComp()->ChangeLevel(1);
							}
							setBudget(getBudget() - car_iterator->CurrentComp()->getCost());
							cout << "Budget Remaining: $" << convertCost(getBudget()) << endl;
							
						}
						selectDepartment();
						
						case 2://upgrade to Level 3
							if(car_iterator->CurrentComp()->getLevel() == 3)
							{
								cout << "This Component is already level 3" << endl;
								selectDepartment();
							}
							else if(car_iterator->CurrentComp()->getLevel() == 1)
							{
								car_iterator->CurrentComp()->ChangeLevel(3);
								if(car_iterator->CurrentComp()->getCost() > getBudget())
								{
									cout << tooExpensive << endl;
									car_iterator->CurrentComp()->ChangeLevel(1);
								}
								
							}
							else if(car_iterator->CurrentComp()->getLevel() == 2){
								car_iterator->CurrentComp()->ChangeLevel(3);
								if(car_iterator->CurrentComp()->getCost() > getBudget())
								{
									cout << tooExpensive << endl;
									car_iterator->CurrentComp()->ChangeLevel(2);
								}
							}
							if(car_iterator->CurrentComp()->getCost() < getBudget()){
							setBudget(getBudget() - car_iterator->CurrentComp()->getCost());
							}
							cout << "Budget Remaining: $" << convertCost(getBudget()) << endl;
							
					
					selectDepartment();
					

					default:
						selectDepartment();
					}
				case 2: //Breaks;
					car_iterator->resetCurrComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
				
					car_iterator->CurrentComp()->ChangeLevel(2);
					convertedCost = convertCost(car_iterator->CurrentComp()->getCost());
					cout << "1. Upgrade to Level 2  ($"<< convertedCost << ")" << endl;
					car_iterator->CurrentComp()->ChangeLevel(3);
					convertedCost = convertCost(car_iterator->CurrentComp()->getCost());
					cout << "2. Upgrade to Level 3  ($" << convertedCost << ")" << endl;
					car_iterator->CurrentComp()->ChangeLevel(1);

					cout << endl;
					
					cin >> choice3;
					switch(choice3){ //select the level
						case 1: //upgrade to Level 2
							//first need to verify if currentBudget() will allow for upgrade. 
						
						if(car_iterator->CurrentComp()->getLevel() == 2){
							cout << "This Component is already Level 2" << endl;
						}
						else{
							car_iterator->CurrentComp()->ChangeLevel(2);
							if(car_iterator->CurrentComp()->getCost() > getBudget())
							{
								cout << tooExpensive << endl;
								car_iterator->CurrentComp()->ChangeLevel(1);
							}
							setBudget(getBudget() - car_iterator->CurrentComp()->getCost());
							cout << "Budget Remaining: $" << convertCost(getBudget()) << endl;
							
						}
						selectDepartment();
						
						case 2://upgrade to Level 3
							if(car_iterator->CurrentComp()->getLevel() == 3)
							{
								cout << "This Component is already level 3" << endl;
								selectDepartment();
							}
							else if(car_iterator->CurrentComp()->getLevel() == 1)
							{
								car_iterator->CurrentComp()->ChangeLevel(3);
								if(car_iterator->CurrentComp()->getCost() > getBudget())
								{
									cout << tooExpensive << endl;
									car_iterator->CurrentComp()->ChangeLevel(1);
								}
								
							}
							else if(car_iterator->CurrentComp()->getLevel() == 2){
								car_iterator->CurrentComp()->ChangeLevel(3);
								if(car_iterator->CurrentComp()->getCost() > getBudget())
								{
									cout << tooExpensive << endl;
									car_iterator->CurrentComp()->ChangeLevel(2);
								}
							}
							if(car_iterator->CurrentComp()->getCost() < getBudget()){
							setBudget(getBudget() - car_iterator->CurrentComp()->getCost());
							}
							cout << "Budget Remaining: $" << convertCost(getBudget()) << endl;
							
					
					selectDepartment();
					

					default:
						selectDepartment();
					}
					case 3: //SurvivalShell;
					car_iterator->resetCurrComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					car_iterator->NextComp();
					
					car_iterator->CurrentComp()->ChangeLevel(2);
					convertedCost = convertCost(car_iterator->CurrentComp()->getCost());
					cout << "1. Upgrade to Level 2  ($"<< convertedCost << ")" << endl;
					car_iterator->CurrentComp()->ChangeLevel(3);
					convertedCost = convertCost(car_iterator->CurrentComp()->getCost());
					cout << "2. Upgrade to Level 3  ($" << convertedCost << ")" << endl;
					car_iterator->CurrentComp()->ChangeLevel(1);

					cout << endl;
					
					cin >> choice3;
					switch(choice3){ //select the level
						case 1: //upgrade to Level 2
							//first need to verify if currentBudget() will allow for upgrade. 
						
						if(car_iterator->CurrentComp()->getLevel() == 2){
							cout << "This Component is already Level 2" << endl;
						}
						else{
							car_iterator->CurrentComp()->ChangeLevel(2);
							if(car_iterator->CurrentComp()->getCost() > getBudget())
							{
								cout << tooExpensive << endl;
								car_iterator->CurrentComp()->ChangeLevel(1);
							}
							setBudget(getBudget() - car_iterator->CurrentComp()->getCost());
							cout << "Budget Remaining: $" << convertCost(getBudget()) << endl;
							
						}
						selectDepartment();
						
						case 2://upgrade to Level 3
							if(car_iterator->CurrentComp()->getLevel() == 3)
							{
								cout << "This Component is already level 3" << endl;
								selectDepartment();
							}
							else if(car_iterator->CurrentComp()->getLevel() == 1)
							{
								car_iterator->CurrentComp()->ChangeLevel(3);
								if(car_iterator->CurrentComp()->getCost() > getBudget())
								{
									cout << tooExpensive << endl;
									car_iterator->CurrentComp()->ChangeLevel(1);
								}
								
							}
							else if(car_iterator->CurrentComp()->getLevel() == 2){
								car_iterator->CurrentComp()->ChangeLevel(3);
								if(car_iterator->CurrentComp()->getCost() > getBudget())
								{
									cout << tooExpensive << endl;
									car_iterator->CurrentComp()->ChangeLevel(2);
								}
							}
							if(car_iterator->CurrentComp()->getCost() < getBudget()){
							setBudget(getBudget() - car_iterator->CurrentComp()->getCost());
							}
							cout << "Budget Remaining: $" << convertCost(getBudget()) << endl;
							
					
					selectDepartment();
					

					default:
						selectDepartment();
					}
			}

		default:
			car_iterator->resetCurrComp();
			return car_iterator->CurrentDept();
			
	}

	
}

int Engineering_Stage::getBudget()
{
	return budget;
}

void Engineering_Stage::setBudget(int budget)
{
	this->budget = budget;
}

Engineering_Iterator* Engineering_Stage::getCarIterator()
{
	return car_iterator;
}


void Engineering_Stage::setEngineering_Iterator(Engineering_Iterator* iterator)
{
	car_iterator = iterator;
}

string Engineering_Stage::convertCost(int costToConvert)
{
	string cost;
	int n;
	cost = to_string(costToConvert);
	n = cost.length() - 3;
	while (n > 0)
	{
		cost.insert(n, ",");
		n -= 3;
	}
	return cost;
}

void Engineering_Stage::init()
{
	// create 4 Departments (to begin with) using addDepartment(Engineering* obj)
	Car_factory *factory = new Car_factory();

	Car = factory->ConstructCar();


	car_iterator = new Engineering_Iterator(Car);

	A_Base_Car *car = new A_Base_Car();

	setBudget(70000000); //budget is initialized to 70,000,000

}


