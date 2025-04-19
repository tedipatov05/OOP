#include "Partial.h"

Fraction& Fraction::operator+=(const Fraction& other){
	this->numenator = this->numenator * other.denominator + other.numenator * this->denominator;
	this->denominator += other.denominator;
	this->Simplify();
	return *this;

}

Fraction& Fraction::operator-=(const Fraction& other) {
	this->numenator = this->numenator * other.denominator - other.numenator * this->denominator;
	this->denominator += other.denominator;
	this->Simplify();
	return *this;
}

Fraction& Fraction::operator*=(const Fraction& other){
	this->numenator *= other.numenator;
	this->denominator *= other.denominator;
	this->Simplify();
	return *this;
}

Fraction& Fraction::operator/=(const Fraction& other){
	this->numenator *= other.denominator;
	this->denominator *= other.numenator;
	this->Simplify();
	return *this;
}

void Fraction::Simplify() {
	int gcd = this->biggestCommonDivider();
	this->numenator /= gcd;
	this->denominator /= gcd;
}

int Fraction::biggestCommonDivider() const {
	int a = this->numenator;
	int b = this->denominator;
	while (b != 0) {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

Fraction operator+(const Fraction& lhs, const Fraction& rhs){
	Fraction lhs1(lhs);
	return lhs1 += rhs;
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
	Fraction lhs1(lhs);
	return lhs1 -= rhs;
}
Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
	Fraction lhs1(lhs);
	return lhs1 *= rhs;
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
	Fraction lhs1(lhs);
	return lhs1 /= rhs;
}
Fraction operator-(const Fraction& other) {
	Fraction other1(other);
	other1.setNumenator(-other1.getNumenator());
	return other1;
}

