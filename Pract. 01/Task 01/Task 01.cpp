// Task 01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//using namespace std;

enum Fruit : uint8_t { APPLE = 100, Orange }; // задава големината на enum


// Little endian - In little-endian byte order, the least significant byte (LSB) is stored at the smallest address,

// Big endian - In big-endian byte order, the most significant byte (MSB) is stored at the smallest address,
// while the least significant byte (LSB) is stored at the largest address.


// union - позволява да се използва една и съща памет за различни типове данни


struct Point {
	int x;
	int y;
};

int findDistanceToCenter(const Point& p) {
	return sqrt(p.x * p.x + p.y * p.y);
}

int distanceBetweenTwoPoints(const Point& p1, const Point& p2) {

	int distanceX = (p1.x - p2.x) * (p1.x - p2.x);
	int distanceY = (p1.y - p2.y) * (p1.y - p2.y);

	return sqrt(distanceX + distanceY);
}

int main()
{
	Point p1;
	std::cin >> p1.x;
	std::cin >> p1.y;
	
	std::cout << "x: " << p1.x << std::endl;
	std::cout << "y: " << p1.y << std::endl;
	
	std::cout << "Distance to center: " << findDistanceToCenter(p1) << std::endl;

	Point p2;
	std::cin >> p2.x;
	std::cin >> p2.y;

	std::cout << "Distance between two points: " << distanceBetweenTwoPoints(p1, p2) << std::endl;

}


