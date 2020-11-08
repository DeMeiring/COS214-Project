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
	
}

Engineering_Iterator* Engineering_Stage::getCarIterator()
{
	return car_iterator;
}


void Engineering_Stage::setEngineering_Iterator(Engineering_Iterator* iterator)
{
	car_iterator = iterator;
}

void Engineering_Stage::init()
{
	// create 4 Departments (to begin with) using addDepartment(Engineering* obj)
	Car_factory *factory = new Car_factory();

	Car = factory->ConstructCar();


	car_iterator = new Engineering_Iterator(Car);

	A_Base_Car *car = new A_Base_Car();
	car->PrototypeCar(car_iterator->CurrentDept());

	// cout <<"====================================="<<endl;
	// cout <<"====================================="<<endl;


	// Engineering_Iterator *iterator = new Engineering_Iterator(ChassisDept);
	// cout<<"Current Departments Initially 4:"<<endl;
	// cout <<"-------------------------------------"<<endl;
	// cout <<"-> "<<iterator->CurrentDept()->getRnDName()<< endl;


	// // cout <<"-> "<< iterator->NextDept()->getRnDName()<< endl;
	// // cout <<"-> "<< iterator->NextDept()->getRnDName()<< endl;
	
	// cout << endl;
	// cout <<"=====================================";
	// cout << endl;
	// cout << endl;

	// int AVGlevel = 0;
	// int cost = 0;
	// int speed = 0;
	// int acceleration = 0;
	// int weight = 0;
	// int handling = 0;
	// int failure = 0;

	// cout<<"Current Components Stats:"<<endl;
	// for(int i =0;i<12;i++){
	// cout <<"-------------------------------------"<<endl;
	// cout << "-> " << iterator->CurrentComp()->getRnDName() << endl;
	// cout <<"-------------------------------------"<<endl;
	// cout <<"Cost: "<< iterator->CurrentComp()->getCost() << endl;
	// cost += iterator->CurrentComp()->getCost();
	// cout <<"Level: "<< iterator->CurrentComp()->getLevel()<<endl;
	// AVGlevel += iterator->CurrentComp()->getLevel();
	// cout <<"-------------------------------------"<<endl;
	
	// cout <<"Speed: "<<iterator->CurrentComp()->getStats()->getValue("speed")<<endl;
	// speed += iterator->CurrentComp()->getStats()->getValue("speed");
	// cout <<"Acceleration: "<< iterator->CurrentComp()->getStats()->getValue("acceleration")<<endl;
	// acceleration += iterator->CurrentComp()->getStats()->getValue("acceleration");
	// cout <<"Weight: "<< iterator->CurrentComp()->getStats()->getValue("weight")<<endl;
	// weight += iterator->CurrentComp()->getStats()->getValue("weight");
	// cout <<"Handling: "<< iterator->CurrentComp()->getStats()->getValue("handling")<<endl;
	// handling += iterator->CurrentComp()->getStats()->getValue("handling");
	// cout <<"Failure: "<< iterator->CurrentComp()->getStats()->getValue("failure")<<endl;
	// failure += iterator->CurrentComp()->getStats()->getValue("failure");

	// if(i!=11)
	// iterator->NextComp();

	// }
	// cout << endl;
	// cout <<"=====================================";
	// cout << endl;
	// cout<<"The Total Stats of the Car"<<endl;
	// cout<<"Speed: "<<speed<<endl;
	// cout<<"Acceleration: "<<acceleration<<endl;
	// cout<<"Weight: "<<weight<<endl;
	// cout<<"Handling: "<<handling<<endl;
	// cout<<"Failure: "<<failure<<endl;

	// cout << endl;
	// cout <<"=====================================";
	// cout << endl;
	// cout<<"The Total Stats of the Car out of 100 which we need to divide by 6 "<<endl;
	// cout<<"Speed: "<<speed/6<<" or -> "<<(speed/6)*10<<"KM/H"<<endl;
	// cout<<"Acceleration: "<<acceleration/6<<endl;
	// cout<<"Weight: "<<weight/6<<" or -> "<<(weight/6)*10<<"KG"<<endl;
	// cout<<"Handling: "<<handling/6<<" or -> "<<(handling/6)<<"%"<<endl;
	// cout<<"Failure: "<<failure/6<<" or -> "<<(failure/6)<<"%"<<endl;

	// cout << "-> " << iterator->NextComp()->getRnDName() << endl;
	// cout << "-> " << iterator->NextComp()->getRnDName() << endl;

	// cout << endl;
	// cout <<"-------------------------------------"<<endl;
	// cout<<"Current Components for Aerodynamics:"<<endl;
	// cout <<"-------------------------------------"<<endl;
	// cout << "-> " << iterator->NextComp()->getRnDName() << endl;
	// cout << "-> " << iterator->NextComp()->getRnDName() << endl;
	// cout << "-> " << iterator->NextComp()->getRnDName() << endl;
	
	
	// cout << endl;
	// cout <<"-------------------------------------"<<endl;
	// cout<<"Current Components for Engine:"<<endl;
	// cout <<"-------------------------------------"<<endl;
	// cout << "-> " << iterator->NextComp()->getRnDName() << endl;
	// cout << "-> " << iterator->NextComp()->getRnDName() << endl;
	// cout << "-> " << iterator->NextComp()->getRnDName() << endl;
	
	
	// cout << endl;
	// cout <<"-------------------------------------"<<endl;
	// cout<<"Current Components for Electronics:"<<endl;
	// cout <<"-------------------------------------"<<endl;
	// cout << "-> " << iterator->NextComp()->getRnDName() << endl;
	// cout << "-> " << iterator->NextComp()->getRnDName() << endl;
	// cout << "-> " << iterator->NextComp()->getRnDName() << endl;
	// cout << "=====================================" << endl;
	// cout << "=====================================" << endl;

	// // cout << iterator->CurrentComp()->getCost() << endl;

	// for (int i = 0; i < 3; i++)
	// 	cout << iterator->CurrentDept()->getComponentList(ChassisDept)[i] << endl;

	// cout << endl;

	// for (int i = 0; i < 3; i++)
	// 	cout << iterator->CurrentDept()->getComponentList(AerodynamicsDept)[i] << endl;
	// cout << endl;

	// for (int i = 0; i < 3; i++)
	// 	cout << iterator->CurrentDept()->getComponentList(EngineDept)[i] << endl;

	// cout << endl;

	// for (int i = 0; i < 3; i++){
	// 	cout << car_iterator->CurrentDept()->getComponentList(EngineDept)[i] << endl;
	// }

	// cout << endl;


	// cout <<iterator->CurrentComp()->getStats()->getValue("acceleration")<< endl;
	// iterator->CurrentComp()->ChangeLevel(2);
	// iterator->CurrentComp()->ChangeLevel(2);
	// cout <<iterator->CurrentComp()->getStats()->getValue("acceleration")<< endl;


	//subject_iterator->

}


