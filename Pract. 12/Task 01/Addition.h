#pragma once
#include "Expression.h"
class Addition : public Expression{


public:

	Addition(const Expression* left, const Expression* right);

	double evaluate() const override;

private:

	const Expression* left;
	const Expression* right;
};

