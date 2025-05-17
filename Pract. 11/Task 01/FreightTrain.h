#pragma once
#include <istream>

#include "Train.h"
class FreightTrain :
    public Train
{
public:
    FreightTrain();
    FreightTrain(size_t year, size_t weight, size_t maxSpeed, size_t wagons, const char* driver, unsigned depotNumber);

    unsigned depotNumber() const;

    friend std::istream& operator>>(std::istream& is, FreightTrain& freight_train);
    friend std::ostream& operator<<(std::ostream& os, const FreightTrain& freight_train);

private:
    unsigned depot_number;
};

