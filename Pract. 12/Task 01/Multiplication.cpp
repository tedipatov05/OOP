#include "Multiplication.h"

Multiplication::Multiplication(const Expression* left, const Expression* right){
	this->left = left;
	this->right = right;
}

double Multiplication::evaluate() const{
	return left->evaluate() * right->evaluate();
}

