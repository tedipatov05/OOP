#include "WheeledVehicle.h"

#include <algorithm>

#include "Constants.h"
#include "Utils.h"

WheeledVehicle::WheeledVehicle() : Vehicle(), _tyres(TYRES){
	this->_number = new char[INITIAL_SIZE] {'\0'};
}

WheeledVehicle::WheeledVehicle(size_t year, size_t weight, size_t maxSpeed, size_t tyres, const char* number)
: Vehicle(year, weight, maxSpeed), _tyres(tyres){
	
	copyString(this->_number, number);
}

WheeledVehicle::WheeledVehicle(size_t tyres, const char* number) : Vehicle(), _tyres(tyres){
	copyString(this->_number, number);
}

WheeledVehicle::WheeledVehicle(const WheeledVehicle& other) : Vehicle(other), _tyres(other.tyres()){
	copyDynamic(other);
}

WheeledVehicle::WheeledVehicle(WheeledVehicle&& other) noexcept : Vehicle(std::move(other)), _tyres(other.tyres()){
	moveDynamic(std::move(other));
}

WheeledVehicle& WheeledVehicle::operator=(const WheeledVehicle& other){
	if (this != &other){
		Vehicle::operator=(other);
		free();
		copyDynamic(other);
		this->_tyres = other.tyres();
	}

	return *this;
}

WheeledVehicle& WheeledVehicle::operator=(WheeledVehicle&& other) noexcept{
	if (this != &other){
		Vehicle::operator=(std::move(other));
		free();
		this->_tyres = other.tyres();
		moveDynamic(std::move(other));
	}

	return *this;
}

WheeledVehicle::~WheeledVehicle(){
	free();
}

const char* WheeledVehicle::number() const{
	return this->_number;
}

size_t WheeledVehicle::tyres() const{
	return this->_tyres;
}



void WheeledVehicle::copyDynamic(const WheeledVehicle& other){
	copyString(this->_number, other.number());
}

void WheeledVehicle::moveDynamic(WheeledVehicle&& other){
	this->_number = other._number;
	other._number = nullptr;
}

void WheeledVehicle::free(){
	delete[] this->_number;
}





