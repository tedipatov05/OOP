#pragma once
class Vehicle{

public:

	Vehicle();
	Vehicle(size_t year, size_t weight, size_t maxSpeed);

	size_t year() const;
	size_t weight() const;
	size_t maxSpeed() const;
protected:

	size_t _year;
	size_t _weight;
	size_t max_speed;
	

};

