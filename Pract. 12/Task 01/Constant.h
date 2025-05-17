#pragma once
#include "Expression.h"

class Constant : public Expression {

public:

	Constant() = default;
	Constant(double value);

	double evaluate() const override;


private:
	double _value;

};

