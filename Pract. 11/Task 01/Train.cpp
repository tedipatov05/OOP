#include "Train.h"

#include <algorithm>

#include "Constants.h"
#include "Utils.h"

Train::Train() : Vehicle(), _wagons(WAGONS){
	this->_driver = new char[INITIAL_SIZE] {'\0'};
}

Train::Train(size_t year, size_t weight, size_t maxSpeed, size_t wagons, const char* driver)
	: Vehicle(year, weight, maxSpeed), _wagons(wagons){

	copyString(this->_driver, driver);
}

Train::Train(size_t wagons, const char* driver) : Vehicle(), _wagons(wagons){
	copyString(this->_driver, driver);
}

Train::Train(const Train& train) : Vehicle(train), _wagons(train.wagons()){
	copyDynamic(train);
}

Train::Train(Train&& train) noexcept: Vehicle(std::move(train)), _wagons(train.wagons()){
	moveDynamic(std::move(train));
}

Train& Train::operator=(const Train& train){
	if (this != &train){
		Vehicle::operator=(train);
		free();
		copyDynamic(train);
		this->_wagons = train.wagons();

	}

	return *this;
}

Train& Train::operator=(Train&& train) noexcept{
	if (this != &train){
		Vehicle::operator=(std::move(train));
		free();
		moveDynamic(std::move(train));
		this->_wagons = train.wagons();
	}

	return *this;
}

Train::~Train(){
	free();
}

const char* Train::driver() const{
	return this->_driver;
}

size_t Train::wagons() const{
	return this->_wagons;
}



void Train::copyDynamic(const Train& train){
	copyString(this->_driver, train.driver());
}
void Train::moveDynamic(Train&& train){
	this->_driver = train._driver;
	train._driver = nullptr;
}

void Train::free(){
	delete[] this->_driver;
}





