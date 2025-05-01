#include "ArrayWriter.h"

#include <fstream>

void ArrayWriter::write(const int* numbers, size_t size) const {
	const char* fileName = "ArrayNumbers.arr";

	std::ofstream arrayWriter(fileName);

	if (!arrayWriter.good())
	{
		return;
	}

	NumbersWriter::write(numbers, size);

	arrayWriter << "[";

	for (size_t i = 0; i < size; i++)
	{
		arrayWriter << numbers[i];

		if (i != size - 1)
		{
			arrayWriter << ",";
		}
	}

	arrayWriter << "]";
}

