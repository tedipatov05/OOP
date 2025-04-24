#include "Vector.h"

#include <algorithm>
#include <stdexcept>

namespace Utils {

	constexpr size_t INITIAL_CAPACITY = 8;

}

namespace {
	static size_t roundToPowerOfTwo(size_t num) {
		num--;
		num |= num >> 1;
		num |= num >> 2;
		num |= num >> 4;
		num |= num >> 8;
		num |= num >> 16;
		num++;
		return num;
	}

	static size_t dataToAllocByStringLen(size_t size)
	{
		return std::max(roundToPowerOfTwo(size + 1), Utils::INITIAL_CAPACITY);
	}

	void setValuesToArr(int*& arr, const int& value, size_t size) {

		for (size_t i = 0; i < size; i++) {
			arr[i] = value;
		}
	}

	void swapValues(size_t& a, size_t& b) {
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}
}



void Vector::copyInts(int*& dest, const int* source, size_t size) {
	for (size_t i = 0; i < size; i++) {
		dest[i] = source[i];
	}
}

Vector::Vector() : _size(0), _capacity(Utils::INITIAL_CAPACITY) {
	this->_data = new int[Utils::INITIAL_CAPACITY];
}

Vector::Vector(size_t size, const int& initialValue) {
	this->_size = size;
	this->_capacity = dataToAllocByStringLen(size);
	this->_data = new int[_capacity];
	setValuesToArr(this->_data, initialValue, size);
}

Vector::Vector(size_t capacity) {
	this->_data = new int[capacity];
	this->_capacity = capacity;
	this->_size = 0;
}

Vector::Vector(const Vector& vector) : _capacity(vector.capacity()), _size(vector.size()) {
	copyDynamic(vector);
}

Vector& Vector::operator=(const Vector& vector) {
	if (this != &vector) {
		freeDynamic();
		copyDynamic(vector);
		this->_capacity = vector.capacity();
		this->_size = vector.size();
	}

	return *this;
}

Vector::~Vector() {
	freeDynamic();
	this->_size = 0;
	this->_capacity = 0;
}



void Vector::freeDynamic() {
	delete[] this->_data;
}

bool Vector::is_empty() const {
	return this->_size == 0;
}

void Vector::copyDynamic(const Vector& vector) {
	this->_data = new int[capacity()];
	copyInts(this->_data, vector.data(), this->size());
}

size_t Vector::size() const {
	return this->_size;
}

const int* Vector::data() const {
	return this->_data;
}

size_t Vector::capacity() const {
	return this->_capacity;
}


const int& Vector::operator[](size_t index) const {
	return this->_data[index];
}

int& Vector::operator[](size_t index) {
	return this->_data[index];
}

void Vector::reserve(size_t newCapacity) {
	if (newCapacity >= this->capacity()) {
		int* temp = new int[newCapacity];
		copyInts(temp, this->data(), this->size());
		delete[] this->_data;
		this->_data = temp;
	}
}

void Vector::shrink_to_fit() {
	if (this->size() != this->capacity()) {
		int* temp = new int[_size];
		copyInts(temp, this->_data, this->size());
		delete[] _data;
		this->_data = temp;
	}
}

void Vector::push_back(const int& value) {
	if (this->size() == this->capacity()) {
		reserve(this->capacity() * 2);
	}

	_data[size()] = value;
	_size++;
}

int& Vector::at(size_t index) {

	if (index < 0 || index > this->size()) {
		throw std::out_of_range("Index out of range");
	}

	return this->_data[index];

}

const int& Vector::at(size_t index) const {

	if (index < 0 || index > this->size()) {
		throw std::out_of_range("Index out of range");
	}

	return this->_data[index];
}

void Vector::clear() {

	for (size_t i = 0; i < this->size(); i++) {
		this->_data[i] = 0;

	}
	this->_size = 0;
}



void Vector::pop_back() {
	if (this->size() == 0) {
		throw std::out_of_range("Could not remove element");
	}

	_size--;

}

void Vector::remove_at(size_t index) {
	if (index < 0 || index > this->size()) {
		throw std::out_of_range("Index out of range");
	}

	for (size_t i = index; i < this->size() - 1; i++) {
		this->_data[i] = this->_data[i + 1];
	}

	_size--;
}

void Vector::insert_at(size_t index, const int& value) {
	if (index < 0 || index > this->size()) {
		throw std::out_of_range("Index out of range");
	}

	if (this->size() == this->capacity()) {
		this->reserve(this->capacity() * 2);
	}

	for (size_t ind = this->size(); ind >= index; ind--) {
		this->_data[ind + 1] = this->_data[ind];
	}

	this->_data[index] = value;
	_size++;

}

void Vector::insert_range(size_t index, const int* values, size_t size) {
	if (index < 0 || index > this->size()) {
		throw std::out_of_range("Index out of range");
	}

	if (this->size() + size > this->capacity()) {
		this->reserve(dataToAllocByStringLen(this->size() + size + 1));
	}

	for (size_t ind = this->size(); ind >= index; ind--) {
		this->_data[ind + size] = this->_data[ind];
	}

	for (size_t i = 0; i < size; i++) {
		this->_data[index + i] = values[i];
	}

	this->_size += size;
}


void Vector::swap(Vector& other)
{

	if (this != &other) {
		int* tempData = this->_data;
		this->_data = other._data;
		other._data = tempData;
		swapValues(this->_size, other._size);
		swapValues(this->_capacity, other._capacity);
	}
	else {
		throw std::invalid_argument("Cannot swap with itself");
	}

}



bool operator==(const Vector& lhs, const Vector& rhs) {
	if (lhs.size() != rhs.size()) {
		return false;
	}

	const int* lhsData = lhs.data();
	const int* rhsData = rhs.data();

	for (size_t i = 0; i < lhs.size(); i++) {
		if (lhsData[i] != rhsData[i]) {
			delete[] lhsData;
			delete[] rhsData;
			return false;
		}
	}

	delete[] lhsData;
	delete[] rhsData;
	return true;
}

bool operator!=(const Vector& lhs, const Vector& rhs) {
	return !(lhs == rhs);
}

bool operator<(const Vector& lhs, const Vector& rhs) {
	if (lhs.size() < rhs.size()) {
		return true;
	}

	if (lhs.size() > rhs.size()) {
		return false;
	}

	const int* lhsData = lhs.data();
	const int* rhsData = rhs.data();

	for (size_t i = 0; i < lhs.size(); i++) {
		if (lhsData[i] < rhsData[i]) {
			delete[] lhsData;
			delete[] rhsData;
			return true;
		}
		else if (lhsData[i] > rhsData[i]) {
			delete[] lhsData;
			delete[] rhsData;
			return false;
		}
	}

	delete[] lhsData;
	delete[] rhsData;
	return false;
}

bool operator>(const Vector& lhs, const Vector& rhs) {
	return (lhs != rhs) && !(lhs < rhs);
}

bool operator<=(const Vector& lhs, const Vector& rhs) {
	return (lhs < rhs) || (lhs == rhs);
}
bool operator>=(const Vector& lhs, const Vector& rhs) {
	return (lhs > rhs) || (lhs == rhs);
}


















