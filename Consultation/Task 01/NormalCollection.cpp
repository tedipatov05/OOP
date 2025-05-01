#include "NormalCollection.h"

NormalCollection::NormalCollection(size_t capacity)
:Collection(new int[capacity], 0) {

	this->capacity = capacity;
}

void NormalCollection::add(int number){
	if (size == capacity){
		resize();
	}

	numbers[size++] = number;
}

void NormalCollection::remove(int number) {
	for (size_t i = 0; i < size; i++){

		if (numbers[i] == number){
			// shiftLeft(i)
			break;
		}
	}
}

size_t NormalCollection::getSize() const{
	return size;
}

bool NormalCollection::contains(int number) const{
	for (size_t i = 0; i < size; i++){
		if (numbers[i] == number){
			return true;
		}
	}

	return false;
}






