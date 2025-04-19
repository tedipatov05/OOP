// Task 01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#pragma warning(disable:4996)

#include "Game.h"

int main()
{

	char** heroes = new char* [2];
	heroes[0] = new char[6] {"Pesho"};
	heroes[1] = new char[6] {"Kamen"};

	Game game("Test", 100,(const char**) heroes, 2);

	std::ofstream ofs("output.txt");
	game.saveInFile(ofs);

	Game game1;
	std::ifstream ifs("output.txt");
	game1.loadFromFile(ifs);

	game1.print();


}

