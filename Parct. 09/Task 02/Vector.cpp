#include "Vector.h"

#include <algorithm>
#include <stdexcept>

namespace Utils {

	const unsigned INITIAL_CAPACITY = 8;

}

namespace {
	static unsigned roundToPowerOfTwo(unsigned num) {
		num--;
		num |= num >> 1;
		num |= num >> 2;
		num |= num >> 4;
		num |= num >> 8;
		num |= num >> 16;
		num++;
		return num;
	}

	static unsigned dataToAllocByStringLen(unsigned size)
	{
		return std::max(roundToPowerOfTwo(size + 1), Utils::INITIAL_CAPACITY);
	}

	void setValuesToArr(int*& arr, const int& value, unsigned size){

		for (unsigned i = 0; i < size; i++){
			arr[i] = value;
		}
	}
}



void Vector::copyInts(int*& dest, const int* source, unsigned size) {
	for (unsigned i = 0; i < size; i++) {
		dest[i] = source[i];
	}
}

Vector::Vector() : size(0), capacity(Utils::INITIAL_CAPACITY) {
	this->_data = new int[Utils::INITIAL_CAPACITY];
}

Vector::Vector(unsigned size, const int& initialValue) {
	this->size = size;
	this->capacity = dataToAllocByStringLen(size);
	this->_data = new int[capacity] ;
	setValuesToArr(this->_data, initialValue, size);
}

Vector::Vector(unsigned capacity) {
	this->_data = new int[capacity];
	this->capacity = capacity;
	this->size = 0;
}

Vector::Vector(const Vector& vector) : capacity(vector.getCapacity()) ,size(vector.getSize()) {
	copyDynamic(vector);
}

Vector& Vector::operator=(const Vector& vector) {
	if (this != &vector) {
		freeDynamic();
		copyDynamic(vector);
		this->capacity = vector.getCapacity();
		this->size = vector.getSize();
	}

	return *this;
}

Vector::~Vector() {
	freeDynamic();
	this->size = 0;
	this->capacity = 0;
}



void Vector::freeDynamic() {
	delete[] this->_data;
}

bool Vector::isEmpty() const {
	return this->size == 0;
}

void Vector::copyDynamic(const Vector& vector) {
	this->_data = new int[getCapacity()];
	copyInts(this->_data, vector.getData(), this->getSize());
}

unsigned Vector::getSize() const {
	return this->size;
}

const int* Vector::getData() const {
	return this->_data;
}

unsigned Vector::getCapacity() const{
	return this->capacity;
}


const int& Vector::operator[](unsigned index) const {
	return this->_data[index];
}

int& Vector::operator[](unsigned index) {
	return this->_data[index];
}

void Vector::reserve(unsigned newCapacity) {
	if (newCapacity >= this->getCapacity()) {
		int* temp = new int[newCapacity];
		copyInts(temp, this->getData(), this->getSize());
		delete[] this->_data;
		this->_data = temp;
	}
}

void Vector::shrinkToFit() {
	if (this->getSize() != this->getCapacity()) {
		int* temp = new int[size];
		copyInts(temp, this->_data, this->getSize());
		delete[] _data;
		this->_data = temp;
	}
}

void Vector::pushBack(const int& value) {
	if (this->getSize() == this->getCapacity()) {
		reserve(this->getCapacity() * 2);
	}

	_data[getSize()] = value;
	size++;
}

int& Vector::at(unsigned index) {

	if (index < 0 || index > this->getSize()) {
		throw std::out_of_range("Index out of range");
	}

	return this->_data[index];

}

const int& Vector::at(unsigned index) const {

	if (index < 0 || index > this->getSize()) {
		throw std::out_of_range("Index out of range");
	}

	return this->_data[index];
}

void Vector::clear(){
	this->size = 0;
}



void Vector::popBack(){
	if (this->getSize() == 0){
		throw std::out_of_range("Could not remove element");
	}

	size--;

}

void Vector::removeAt(unsigned index){
	if (index < 0 || index > this->getSize()) {
		throw std::out_of_range("Index out of range");
	}

	for (unsigned i = index; i < this->getSize() - 1; i++){
		this->_data[i] = this->_data[i + 1];
	}

	size--;
}

void Vector::insertAt(unsigned index, const int& value){
	if (index < 0 || index > this->getSize()) {
		throw std::out_of_range("Index out of range");
	}

	if (this->getSize() == this->getCapacity()){
		this->reserve(this->getCapacity() * 2);
	}

	for (unsigned ind = this->getSize(); ind >= index; ind-- ){
		this->_data[ind + 1] = this->_data[ind];
	}

	this->_data[index] = value;
	size++;

}

bool operator==(const Vector& lhs, const Vector& rhs){
	if (lhs.getSize() != rhs.getSize()){
		return false;
	}

	const int* lhsData = lhs.getData();
	const int* rhsData = rhs.getData();

	for (unsigned i = 0; i < lhs.getSize(); i++){
		if (lhsData[i] != rhsData[i]){
			delete[] lhsData;
			delete[] rhsData;
			return false;
		}
	}

	delete[] lhsData;
	delete[] rhsData;
	return true;
}















