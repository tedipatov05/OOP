#include "Product.h"
#include <iostream>
#pragma warning(disable:4996)
#include "Constants.h"
#include "Utils.h"

Product::Product(){
	this->_name = new char[INITIAL_CAPACITY];
}

void Product::free(){
	delete[] this->_name;
}

Product::~Product(){
	free();
}

Product::Product(const Product& product){
	copyDynamic(product._name);
}

void Product::copyDynamic(const char* name){
	size_t len = std::strlen(name);
	this->_name = new char[len + 1];
	std::strcpy(this->_name, name);
	this->_name[len] = '\0';
}

Product::Product(const char* name){
	copyDynamic(name);
}

Product::Product(Product&& product) noexcept{
	copyMove(std::move(product));
}


Product& Product::operator=(const Product& product){
	if (this != &product){
		free();
		copyDynamic(product._name);
	}

	return *this;
}

Product& Product::operator=(Product&& product) noexcept{
	if (this != &product){
		free();
		copyMove(std::move(product));
	}

	return *this;
}

std::istream& operator>>(std::istream& is, Product& product){
	readString(is, product._name);

	return is;
}

void Product::copyMove(Product&& product){
	this->_name = product._name;
	product._name = nullptr;
}

bool operator==(const Product& lhs, const Product& rhs){
	return std::strcmp(lhs.name(), rhs.name());
}

const char* Product::name() const{
	return this->_name;
}










