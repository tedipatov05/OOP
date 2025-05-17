#include "Jeep.h"

Jeep::Jeep() : WheeledVehicle(), _is4x4(false){
	
}

Jeep::Jeep(size_t year, size_t weight, size_t maxSpeed, size_t tyres, const char* number, bool is4x4)
: WheeledVehicle(year, weight, maxSpeed, tyres, number), _is4x4(is4x4){
	
}

bool Jeep::is4x4() const{
	return this->_is4x4;
}



