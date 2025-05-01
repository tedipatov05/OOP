#pragma once

class Fraction
{
public:
	Fraction& operator+=(const Fraction& other);
	Fraction& operator-=(const Fraction& other);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);

	void Simplify();

	int getDenominator() const;
	int getNumenator() const;

	void setDenominator(int denominator);

	void setNumenator(int numenator);
private:
	int denominator;
	int numenator;

	int biggestCommonDivider() const;
};

Fraction operator+(const Fraction& lhs, const Fraction& rhs);
Fraction operator-(const Fraction& lhs, const Fraction& rhs);
Fraction operator*(const Fraction& lhs, const Fraction& rhs);
Fraction operator/(const Fraction& lhs, const Fraction& rhs);

Fraction operator-(const Fraction& other);
Fraction operator++(Fraction& other);
Fraction operator--(Fraction& other);


bool operator==(const Fraction& lhs, const Fraction& rhs);
bool operator!=(const Fraction& lhs, const Fraction& rhs);
bool operator<(const Fraction& lhs, const Fraction& rhs);


