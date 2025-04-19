#include "MyString.h"

#include <istream>
#pragma warning(disable : 4996) // Disable deprecation warning for strcpy

namespace Utils {

	constexpr unsigned INITIAL_CAPACITY = 16u;
	constexpr int BUFFER_SIZE = 1024;

	
}

MyString::MyString() : MyString(""){}

void MyString::copyString(char*& dest, const char* src, unsigned capacity) const {
	if (src == nullptr) {
		dest = nullptr;
		return;
	}
	size_t len = strlen(src) + 1;
	dest = new char[capacity];
	strcpy(dest, src);
	dest[len] = '\0';

}

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

static unsigned dataToAllocByStringLen(unsigned stringLength)
{
	return std::max(roundToPowerOfTwo(stringLength + 1), Utils::INITIAL_CAPACITY);
}

MyString::MyString(const char* str) {
	if (str == nullptr) {
		this->_data = nullptr;
		this->capacity = 0;
		return;
	}

	this->capacity = dataToAllocByStringLen(strlen(str));
	copyString(this->_data, str, this->getCapacity());
}

MyString::MyString(const MyString& str) : capacity(str.getCapacity()) {
	copyDynamic(str);
}

MyString::~MyString() {
	freeDynamic();
	this->capacity = 0;
}

MyString& MyString::operator=(const MyString& str) {
	if (this != &str) {
		freeDynamic();
		copyDynamic(str);
		this->capacity = str.getCapacity();
	}
	return *this;
}

MyString& MyString::operator+=(const MyString& str) {
	if (str.getString() == nullptr) {
		return *this;
	}

	if (this->getSize() + str.getSize() + 1 > this->getCapacity()){
		this->resize(this->getSize() + str.getSize());
	}

	std::strncat(this->_data, str.getString(), str.getSize());

	return *this;


}

unsigned MyString::getSize() const {
	return unsigned(strlen(_data));
}

unsigned MyString::getCapacity() const {
	return capacity;
}

const char* MyString::getString() const {
	return _data;
}

char& MyString::operator[](unsigned index) {
	return _data[index];
}

const char& MyString::operator[](unsigned index) const {
	return _data[index];
}



MyString operator+(const MyString& lhs, const MyString& rhs) {
	MyString result(lhs);
	result += rhs;
	return result;
}


void MyString::copyDynamic(const MyString& other) {
	if (other.getString() == nullptr) {
		this->_data = nullptr;
		return;
	}
	copyString(this->_data, other.getString(), other.capacity);
}

void MyString::freeDynamic() {
	delete[] _data;
	_data = nullptr;
}

bool operator==(const MyString& lhs, const MyString& rhs) {
	return strcmp(lhs.getString(), rhs.getString()) == 0;
}
bool operator!=(const MyString& lhs, const MyString& rhs) {
	return !(lhs == rhs);
}

bool operator<(const MyString& lhs, const MyString& rhs) {
	return strcmp(lhs.getString(), rhs.getString()) < 0;
}

bool operator>(const MyString& lhs, const MyString& rhs) {
	return strcmp(lhs.getString(), rhs.getString()) > 0;
}

bool operator<=(const MyString& lhs, const MyString& rhs) {
	return !(lhs > rhs);
}

bool operator>=(const MyString& lhs, const MyString& rhs) {
	return !(lhs < rhs);
}

void MyString::resize(unsigned newCapacity){

	char* temp = new char[newCapacity];
	strcpy(temp, _data);
	delete[] _data;
	this->_data = temp;
	this->capacity = newCapacity;

}


std::ostream& operator<<(std::ostream& os, const MyString& str){

	os << str.getString();
	return os;
	
}

std::istream& operator>>(std::istream& is, MyString& str){

	char buffer[Utils::BUFFER_SIZE];
	is >> buffer;
	size_t bufferStringSize = std::strlen(buffer);

	if (bufferStringSize > str.getCapacity()){
		str.resize(roundToPowerOfTwo(bufferStringSize));
	}

	std::strcpy(str._data, buffer);
	return is;



}



