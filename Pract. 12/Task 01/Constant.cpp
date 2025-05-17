#include "Constant.h"

Constant::Constant(double value) : _value(value){
	
}

double Constant::evaluate() const{
	return this->_value;
}

Constant operator+(const Constant& lhs, const Constant& rhs){
	Constant constant(lhs);
}
