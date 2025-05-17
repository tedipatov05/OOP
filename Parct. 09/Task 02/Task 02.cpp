
#include <iostream>
#include <vector>

#include "Vector.h"

int main()
{
    Vector vector(8);

    vector.push_back(15);
    vector.push_back(20);
    vector.push_back(30);
    vector.insert_at(2, 11);

	vector.insert_range(0, new int[2] { 5, 10 }, 2);

	std::cout << vector[0] << std::endl; // should be 5
	std::cout << vector[1] << std::endl; // should be 10
	std::cout << vector[2] << std::endl; // should be 15
	std::cout << vector[3] << std::endl; // should be 20
	std::cout << vector[4] << std::endl; // should be 11

	vector.shrink_to_fit();
	std::cout << vector.capacity();




}

