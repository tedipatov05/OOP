#pragma once
#include "Vehicle.h"
class Train :
    public Vehicle
{
public:

    Train();
    Train(size_t year, size_t weight, size_t maxSpeed, size_t wagons, const char* driver);
    Train(size_t wagons, const char* driver);
    Train(const Train& train);
    Train(Train&& train) noexcept;
    Train& operator=(const Train& train);
    Train& operator=(Train&& train) noexcept;
    ~Train();

    const char* driver() const;
    size_t wagons() const;

protected:

    size_t _wagons;
    char* _driver;

private:
    void free();
    void copyDynamic(const Train& train);
    void moveDynamic(Train&& train);
};

