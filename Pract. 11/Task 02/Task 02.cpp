// Task 02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Commander.h"
#include "General.h"
#include "Soldier.h"

int main()
{
	Soldier soldier(Soldier("Peter", 20, 40, 1040.31));
	Soldier soldier2(Soldier("Ivan", 22, 500, 10000));
	Soldier soldier3(Soldier("Petko", 25, 120, 5000));

	Soldier soldiers[3] = { soldier, soldier2, soldier3 };

	Commander commander("Georgi", 20000, 400, 30, soldiers, 3);
	Commander commanders[1] = { commander };

	General general("Teo", 30000, 530, 34, commanders, 1, "test");

	general.saveinFile(std::cout);

}
