// Task 01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

namespace GLOBAL_CONSTANTS
{
	constexpr int MAX_LEN = 20;
	const char* FILE_NAME = "people.dat";
}

struct Person
{
	char name[GLOBAL_CONSTANTS::MAX_LEN];
	int age;
};

void saveToFile(const char* filename, const Person* people, size_t size){

	std::ofstream ofs(filename, std::ios::binary);

	if (!ofs.is_open()){
		return;
	}

	ofs.write((const char*)people, size * sizeof(Person));
	ofs.close();
}

size_t getFileSize(std::ifstream& ifs)
{
	size_t currPos = ifs.tellg();
	ifs.seekg(0, std::ios::end);
	size_t size = ifs.tellg();
	ifs.seekg(currPos, std::ios::beg);
	return size;
}

Person* readPeopleArrayFromFile(const char* filename, size_t& size){
	std::ifstream ifs(filename, std::ios::binary);

	if (!ifs.is_open()){
		return nullptr;
	}

	int count = getFileSize(ifs);
	size = count / sizeof(Person);

	Person* people = new Person[size];

	ifs.read((char*) people, size* sizeof(Person));

	ifs.close();

	return people;

	
}

int main()
{
	Person arr[] = { {"Boris", 20}, {"Momchil", 10} };
	saveToFile(GLOBAL_CONSTANTS::FILE_NAME, arr, 2);
}

