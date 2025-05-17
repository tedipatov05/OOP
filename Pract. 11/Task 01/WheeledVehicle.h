#pragma once
#include "Vehicle.h"
class WheeledVehicle :
    public Vehicle
{
public:
    WheeledVehicle();
    WheeledVehicle(size_t year, size_t weight, size_t maxSpeed, size_t tyres, const char* number);
    WheeledVehicle(size_t tyres, const char* number);
    WheeledVehicle(const WheeledVehicle& other);
    WheeledVehicle(WheeledVehicle&& other) noexcept;
    WheeledVehicle& operator=(const WheeledVehicle& other);
    WheeledVehicle& operator=(WheeledVehicle&& other) noexcept;
    ~WheeledVehicle();

    const char* number() const;
    size_t tyres() const;

protected:
    size_t _tyres;
    char* _number;

private:
    void copyDynamic(const WheeledVehicle& other);
    void moveDynamic(WheeledVehicle&& other);
    void free();
    
};

