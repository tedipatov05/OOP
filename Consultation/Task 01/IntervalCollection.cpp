#include "IntervalCollection.h"

#include <__msvc_filebuf.hpp>

IntervalCollection::IntervalCollection(int start, int end) : Collection(){
	numbers = new int[end - start + 1];
	size = end - start + 1;

	this->start = start;
	this->end = end;
}

void IntervalCollection::add(int number){
	if (number < start || number > end){
		return;
	}

	int index = number - start;

	numbers[index]++; 
}

void IntervalCollection::remove(int number){
	if (number < start || number > end){
		throw std::invalid_argument("Invalid argument");
	}

	int index = number - start;

	if (numbers[index] == 0){
		throw std::invalid_argument("this number is not in the collection");
	}

	numbers[index]--;
}

size_t IntervalCollection::getSize() const{
	size_t numbersCount = 0;

	for (size_t i = 0; i < size; i++){
		numbersCount += numbers[i];
	}

	return numbersCount;
}

bool IntervalCollection::contains(int number) const{
	if (number < start || number > end){
		return false;
	}

	int index = number - start;

	return numbers[index] != 0;

}





