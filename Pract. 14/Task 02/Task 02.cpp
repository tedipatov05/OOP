// Task 02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Optional.hpp"

int main()
{
	Optional<int> opt1(10);

	std::cout << opt1.value() << std::endl;
	std::cout << *opt1 << std::endl;

	std::cout << std::boolalpha << opt1.has_value() << std::endl;
	std::cout << opt1.value_or(20) << std::endl;
	opt1.reset();
	std::cout << std::boolalpha << opt1.has_value() << std::endl;
	std::cout << opt1.value_or(20) << std::endl;
}

