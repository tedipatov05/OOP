#include "ConsoleWriter.h"

#include <fstream>
#include <iostream>

void ConsoleWriter::write(const int* numbers, size_t size) const{
	NumbersWriter::write(numbers, size);

	for (size_t i = 0; i < size; i++)
	{
		std::cout << numbers[i] << " ";
	}
}

