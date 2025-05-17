#pragma once
#include "Expression.h"
class Multiplication : public Expression{
public:

	Multiplication(const Expression* left, const Expression* right);

	double evaluate() const override;

private:

	const Expression* left;
	const Expression* right;
};

