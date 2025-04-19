// Task 02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "Song.h"


int main()
{
	char* songName = new char[7] {"Bogota"};

	std::ofstream ofs("output.dat", std::ios::binary | std::ios::trunc);

	if (!ofs.is_open()) {
		return 0;
	}
	uint8_t arr[] = { 90, 90 };

	size_t size = 2;

	ofs.write((const char*)&size, sizeof(size));
	ofs.write((const char*)arr, size*sizeof(uint8_t));

	ofs.close();

	Song song(songName, 345, "rp", "output.dat");

	std::cout << (int)song.getGenre() << std::endl;
	song.printContent();
}

