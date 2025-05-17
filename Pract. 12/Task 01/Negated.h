#pragma once
#include "Constant.h"

class Negated : public Expression {

public:
	Negated() = default;
	Negated(const Expression* expr);

	double evaluate() const override;

private:

	const Expression* value;
};

