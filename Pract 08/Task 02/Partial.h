#pragma once

class Fraction
{
public:
	Fraction& operator+=(const Fraction& other);
	Fraction& operator-=(const Fraction& other);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);

	void Simplify();

	int getDenominator() const{
		return this->denominator;
	}

	int getNumenator() const {
		return this->numenator;
	}

	void setDenominator(int denominator) {
		this->denominator = denominator;
	}

	void setNumenator(int numenator) {
		this->numenator = numenator;
	}

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


