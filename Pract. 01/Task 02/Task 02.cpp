// Task 02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//using namespace std;

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

struct Trianagle {
	Point a;
	Point b;
	Point c;
};

enum TypeTrianagle {
	Equilateral,
	Isosceles,
	Scalene
};

int findSurface(const Trianagle& t) {
	int a = distanceBetweenTwoPoints(t.a, t.b);
	int b = distanceBetweenTwoPoints(t.b, t.c);
	int c = distanceBetweenTwoPoints(t.c, t.a);

	int p = (a + b + c) / 2;

	return sqrt(p * (p -a) * (p - b) * (p - c));
}

int findPerimeter(const Trianagle& t) {
	int a = distanceBetweenTwoPoints(t.a, t.b);
	int b = distanceBetweenTwoPoints(t.b, t.c);
	int c = distanceBetweenTwoPoints(t.c, t.a);

	return a + b + c;
}

TypeTrianagle findTypeTrianagle(const Trianagle& t) {
	int a = distanceBetweenTwoPoints(t.a, t.b);
	int b = distanceBetweenTwoPoints(t.b, t.c);
	int c = distanceBetweenTwoPoints(t.c, t.a);

	if (a == b && b == c) {
		return Equilateral;
	}
	else if (a == b || b == c || a == c) {
		return Isosceles;
	}
	else {
		return Scalene;
	}
}

void printTypeTrianagle(const Trianagle& t) {

	switch (findTypeTrianagle(t)) {
		case Equilateral:
			std::cout << "Equilateral" << std::endl;
			break;
		case Isosceles:
			std::cout << "Isosceles" << std::endl;
			break;
		case Scalene:
			std::cout << "Scalene" << std::endl;
			break;
	}
}

void sortTrianagles(Trianagle* trianagles, int n) {
	for (size_t i = 0; i < n; i++) {
		for (size_t j = i + 1; j < n; j++) {
			if (findSurface(trianagles[i]) > findSurface(trianagles[j])) {
				Trianagle temp = trianagles[i];
				trianagles[i] = trianagles[j];
				trianagles[j] = temp;
			}
		}
	}
}

void printPoint(const Point& p){

	std::cout << "x: " << p.x;
	std::cout << " y: " << p.y << std::endl;
	
}

void printTrianagles(const Trianagle* trianagles, int n){

	for (size_t i = 0; i < n; i++)
	{
		std::cout << "Trianagle: " << std::endl;
		printPoint(trianagles[i].a);
		printPoint(trianagles[i].b);
		printPoint(trianagles[i].c);
	}
}

void inputTrianagle(Trianagle& t){

	Point p1;
	std::cin >> p1.x;
	std::cin >> p1.y;

	Point p2;
	std::cin >> p2.x;
	std::cin >> p2.y;

	Point p3;
	std::cin >> p3.x;
	std::cin >> p3.y;

	t.a = p1;
	t.b = p2;
	t.c = p3;
}


int main()
{
	Trianagle t;

	inputTrianagle(t);

	int a = distanceBetweenTwoPoints(t.a, t.b);
	int b = distanceBetweenTwoPoints(t.b, t.c);
	int c = distanceBetweenTwoPoints(t.c, t.a);

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;

	std::cout << "Surface: " << findSurface(t) << std::endl;
	std::cout << "Perimeter: " << findPerimeter(t) << std::endl;

	std::cout << "Type of trianagle: " << printTypeTrianagle;

	int n;
	std::cin >> n;
	Trianagle* trianagles = new Trianagle[10];
	for (size_t i = 0; i < n; i++) {
		inputTrianagle(trianagles[i]);
	}


}

