#include "ComplexNumber.h"

#include <iostream>
#include <iso646.h>
#include <ostream>


ComplexNumber& ComplexNumber::operator+=(const ComplexNumber& other) {
	real += other.real;
	imaginary += other.imaginary;
	return *this;
}

ComplexNumber& ComplexNumber::operator*=(const ComplexNumber& other){
	real = (real * other.real - imaginary * other.imaginary);
	imaginary = (real * other.imaginary + imaginary * other.real);
	return *this;
}

ComplexNumber& ComplexNumber::operator-=(const ComplexNumber& other){
	real -= other.real;
	imaginary -= other.imaginary;
	return *this;
}

ComplexNumber& ComplexNumber::operator/=(const ComplexNumber& other) {
	real = (real * other.real + imaginary * other.imaginary) / (other.real * other.real + other.imaginary * other.imaginary);
	imaginary = (imaginary * other.real - real * other.imaginary) / (other.real * other.real + other.imaginary * other.imaginary);
	return *this;
}


ComplexNumber operator+(const ComplexNumber& lhs, const ComplexNumber& rhs) {
	ComplexNumber result = lhs;
	result += rhs;
	return result;
}

ComplexNumber operator-(const ComplexNumber& lhs, const ComplexNumber& rhs) {
	ComplexNumber result = lhs;
	result -= rhs;
	return result;
}

ComplexNumber operator~(const ComplexNumber& complexNumber){
	ComplexNumber complex(complexNumber);
	complex.imaginary = -complex.imaginary;

	return complex;
}


ComplexNumber operator*(const ComplexNumber& lhs, const ComplexNumber& rhs) {
	ComplexNumber result = lhs;
	result *= rhs;
	return result;
}

ComplexNumber operator/(const ComplexNumber& lhs, const ComplexNumber& rhs) {
	ComplexNumber result = lhs;
	result /= rhs;
	return result;
}

bool operator==(const ComplexNumber& lhs, const ComplexNumber& rhs) {
	return (lhs.getRealPart() == rhs.getRealPart() && lhs.getImaginary() == rhs.getImaginary());
}

bool operator!=(const ComplexNumber& lhs, const ComplexNumber& rhs) {
	return !(lhs == rhs);
}

bool operator<(const ComplexNumber& lhs, const ComplexNumber& rhs) {
	return (lhs.getRealPart() < rhs.getRealPart() || (lhs.getRealPart() == rhs.getRealPart() && lhs.getImaginary() < rhs.getImaginary()));
}

bool operator>(const ComplexNumber& lhs, const ComplexNumber& rhs) {
	return (lhs.getRealPart > rhs.getRealPart || (lhs.getRealPart() == rhs.getRealPart() && lhs.getImaginary() > rhs.getImaginary()));
}

std::istream& operator>>(std::istream& is, ComplexNumber& complexNumber){

	is >> complexNumber.real;
	is >> complexNumber.imaginary;

	return is;
}

double ComplexNumber::getRealPart() const {
	return this->real;
}

double ComplexNumber::getImaginary() const {
	return this->imaginary;
}


std::ostream& operator<<(std::ostream& os, const ComplexNumber& complexNumber){

	os << complexNumber.getRealPart() << " " << complexNumber.getImaginary() << std::endl;

	return os;
}

