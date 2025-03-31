// Task 02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

namespace Constants
{
	constexpr int INITIAL_SIZE = 8;
	constexpr int MIN = INT32_MIN;
}


class Stack{
	
	int* elements;
	size_t currentSize;
	size_t size;

	void copyIntArr(int*& destination, size_t& size,size_t& currentSize ,const int* source, size_t sizeOther, size_t currentSizeOther){
		destination = new int[sizeOther];
		size = sizeOther;
		currentSize = currentSizeOther;

		for (size_t i = 0; i < size; i++){

			destination[i] = source[i];
		}

	}

	void free(){
		delete[] this->elements;
	}

	void copyFrom(const Stack& other){

		copyIntArr(this->elements, this->size, this->currentSize, other.elements, other.size, other.currentSize);
	}

	void resize(int newSize){

		int* temp = new int[newSize];

		for (size_t i = 0; i < this->size; i++) {
			temp[i] = this->elements[i];
		}

		this->size = newSize;
		delete[] this->elements;

		this->elements = temp;

	}


public:
	Stack(){
		this->elements = new int[Constants::INITIAL_SIZE];
		this->currentSize = 0;
		this->size = Constants::INITIAL_SIZE;
	}

	Stack(const Stack& other){
		copyFrom(other);
	}

	Stack(int* arr, size_t size) {
		copyIntArr(this->elements, this->size, this->currentSize, arr, size, size);
	}

	Stack& operator=(const Stack& other){
		if (this != &other){
			free();
			copyFrom(other);

		}
		return *this;
	}

	~Stack(){
		free();
	}

	void Push(int a){

		if (this->currentSize == size){
			resize(size * 2);
		}

		this->elements[currentSize++] = a;
	}

	int Pop() {
		if (currentSize == 0) {
			return -1;
		}

		int lastElem = this->elements[currentSize-1];

		this->elements[currentSize-1] = Constants::MIN;
		currentSize--;

		return lastElem;
	}

	int Peek() {
		return this->elements[currentSize-1];
	}

};

int main()
{

	int arr[5] = { 1,2,3,4,5 };

	Stack* stack = new Stack(arr, 5);
	std::cout << stack->Peek() << std::endl;
	stack->Pop();
	std::cout << stack->Peek() << std::endl;
	stack->Push(11);
	std::cout << stack->Peek() << std::endl;

	delete stack;
    
}

