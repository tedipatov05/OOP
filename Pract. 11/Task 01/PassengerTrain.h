#pragma once
#include <ostream>

#include "Train.h"
class PassengerTrain :
    public Train
{
public:

    PassengerTrain();
    PassengerTrain(size_t year, size_t weight, size_t maxSpeed, size_t wagons, const char* driver, size_t passengers);

    size_t passengers() const;

    friend std::ostream& operator<<(std::ostream& os, const PassengerTrain& passenger_train);
    friend std::istream& operator>>(std::istream& is, PassengerTrain& passenger_train);

private:

    size_t _passengers;
};

