#include "Addition.h"

Addition::Addition(const Expression* left, const Expression* right){
	this->left = left;
	this->right = right;
}

double Addition::evaluate() const{
	return left->evaluate() + right->evaluate();
}


