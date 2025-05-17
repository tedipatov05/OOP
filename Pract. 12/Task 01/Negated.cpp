#include "Negated.h"

Negated::Negated(const Expression* expr){
	this->value = expr;
}

double Negated::evaluate() const{
	return this->evaluate() - 2 * this->evaluate();
}


