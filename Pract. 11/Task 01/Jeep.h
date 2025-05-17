#pragma once
#include "WheeledVehicle.h"
class Jeep :
    public WheeledVehicle
{
public:

    Jeep();
    Jeep(size_t year, size_t weight, size_t maxSpeed, size_t tyres, const char* number, bool is4x4);

    bool is4x4() const;

private:

    bool _is4x4;
};

