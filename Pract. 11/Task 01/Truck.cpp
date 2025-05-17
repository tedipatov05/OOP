#include "Truck.h"


Truck::Truck() : WheeledVehicle(), truck_capacity(0){
	
}

Truck::Truck(size_t year, size_t weight, size_t maxSpeed, size_t tyres, const char* number, size_t truckCapacity)
	: WheeledVehicle(year, weight, maxSpeed, tyres, number), truck_capacity(truckCapacity){
	
}


