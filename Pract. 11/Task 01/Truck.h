#pragma once
#include "WheeledVehicle.h"
class Truck :
    public WheeledVehicle
{
public:
    Truck();
    Truck(size_t year, size_t weight, size_t maxSpeed, size_t tyres, const char* number, size_t truckCapacoty);
private:
    size_t truck_capacity;

};

