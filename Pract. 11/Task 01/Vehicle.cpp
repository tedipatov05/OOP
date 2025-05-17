#include "Vehicle.h"

Vehicle::Vehicle() : _year(2020), _weight(1000), max_speed(140){
	
}

Vehicle::Vehicle(size_t year, size_t weight, size_t maxSpeed)
: _year(year), _weight(weight), max_speed(maxSpeed){
	
}

size_t Vehicle::maxSpeed() const{
	return this->max_speed;
}

size_t Vehicle::weight() const{
	return this->_weight;
}

size_t Vehicle::year() const{
	return this->_year;
}





