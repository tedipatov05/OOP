#pragma once
#include <ostream>

class ComplexNumber {

public:

	ComplexNumber& operator+=(const ComplexNumber& other);
	ComplexNumber& operator-=(const ComplexNumber& other);
	ComplexNumber& operator*=(const ComplexNumber& other);
	ComplexNumber& operator/=(const ComplexNumber& other);

	
	friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& complexNumber);
	friend std::istream& operator>>(std::istream& is, ComplexNumber& complexNumber);
	friend ComplexNumber operator~(const ComplexNumber& complexNumber);

	double getRealPart() const;

	double getImaginary() const;

private:
	double real;
	double imaginary;

};

ComplexNumber operator+(const ComplexNumber& lhs, const ComplexNumber& rhs);
ComplexNumber operator-(const ComplexNumber& lhs, const ComplexNumber& rhs);
ComplexNumber operator*(const ComplexNumber& lhs, const ComplexNumber& rhs);
ComplexNumber operator/(const ComplexNumber& lhs, const ComplexNumber& rhs);
ComplexNumber operator~();

bool operator==(const ComplexNumber& lhs, const ComplexNumber& rhs);
bool operator!=(const ComplexNumber& lhs, const ComplexNumber& rhs);
bool operator<(const ComplexNumber& lhs, const ComplexNumber& rhs);
bool operator>(const ComplexNumber& lhs, const ComplexNumber& rhs);
