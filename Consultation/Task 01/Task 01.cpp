// Task 01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "ArrayWriter.h"
#include "BinaryWriter.h"
#include "Collection.h"
#include "ConsoleWriter.h"
#include "IntervalCollection.h"
#include "NormalCollection.h"
#include "NumbersWriter.h"

NumbersWriter* numbersWriterFactory(int writeType)
{
	switch (writeType)
	{
	case 1:
		return new ConsoleWriter();
	case 2:
		return new BinaryWriter();
	case 3:
		return new ArrayWriter();
	default:
		return nullptr;
	}
}

Collection* collectionFactory(int collectionType)
{
	switch (collectionType)
	{
	case 1:
		return new NormalCollection(10);
	case 2:
		return new IntervalCollection(5, 10);
	default:
		return nullptr;
	}
}


int main()
{
    std::cout << "Hello World!\n";
}

