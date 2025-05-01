#include "Collection.h"

Collection::Collection(const int* numbers, size_t size){
	copy(numbers, size);
}

void Collection::print(NumbersWriter* numbers_writer) const{
	numbers_writer->write(this->numbers, this->size);
}

void Collection::copy(const int* numbers, size_t size){
	if (!numbers){
		this->numbers = new int[1];
		size = 0;
	}

	this->numbers = new int[size];
	for (size_t i = 0; i < size; i++){
		this->numbers[i] = numbers[i];
	}
}



