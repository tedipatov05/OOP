// Demo 01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

namespace Constants
{
	constexpr int elementsInBucket = 8;
	constexpr uint8_t leftMostBit = (1 << 7);
}

class Set
{

public:
	Set()
	{
		bitset = nullptr;
		buckets = -1;
		maxElement = -1;
	}

	Set(int maxElement) : maxElement(maxElement)
	{
		initializeBitset(maxElement);
	}

	void addElement(int element)
	{
		int bucket = getBucket(element);
		int indexInBucket = getIndexInBucket(element);

		uint8_t mask = Constants::leftMostBit;
		mask = (mask << indexInBucket);

		bitset[bucket] = (bitset[bucket] | mask);


	}

	void removeElement(int element)
	{
		int bucket = getBucket(element);
		int indexInBucket = getIndexInBucket(element);

		uint8_t mask = Constants::leftMostBit;
		mask = (mask << indexInBucket);

		mask = ~mask;
		bitset[bucket] = (bitset[bucket] & mask);


	}

	void print() const
	{
		int number = 0;
		for (int i = 0; i < buckets; i++)
		{
			uint8_t mask = Constants::leftMostBit;
			for (int j = 0; j < Constants::elementsInBucket; j++)
			{
				bool isIncluded = (bitset[i] & mask);

				if (isIncluded)
				{
					std::cout << number << " ";
				}

				mask = mask << 1;

				number++;

			}
		}
	}



private:
	uint8_t* bitset;
	int buckets;
	int maxElement;

	void initializeBitset(int maxElement)
	{
		int buckets = maxElement / Constants::elementsInBucket + 1;
		bitset = new uint8_t[buckets]{ 0 };
		this->buckets = buckets;
	}

	int getBucket(int element) const
	{
		return element / Constants::elementsInBucket;
	}
	int getIndexInBucket(int element)
	{
		return element % Constants::elementsInBucket;
	}
};

int main()
{
	std::cout << "Hello World!\n";
}

