// Task 01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Pair.hpp"

int main()
{
	Pair<int, char> pair1(1, 'a');

	std::cout << pair1 << std::endl;

	Pair<int, char> pair2(2, 'b');

	bool result = pair1 < pair2;
	bool result2 = pair1 == pair2;

	std::cout << "pair1 < pair2: " << std::boolalpha << result << std::endl;
	std::cout << "pair1 == pair2: " << std::boolalpha << result2 << std::endl;

}

