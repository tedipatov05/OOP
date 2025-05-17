#include "PassengerTrain.h"
#include <iostream>

#include "Utils.h"
#include "../Task 02/Constants.h"

PassengerTrain::PassengerTrain() : Train(), _passengers(0){
	
}

PassengerTrain::PassengerTrain(size_t year, size_t weight, size_t maxSpeed, size_t wagons, const char* driver, size_t passengers)
	: Train(year, weight, maxSpeed, wagons, driver), _passengers(passengers){
	
}

size_t PassengerTrain::passengers() const{
	return this->_passengers;
}

std::ostream& operator<<(std::ostream& os, const PassengerTrain& passenger_train){
	os << passenger_train.year() << " " << passenger_train.weight() << " " << passenger_train.maxSpeed() << " " << passenger_train.wagons()
	<< " " << passenger_train.driver() << " " << passenger_train.passengers();

	return os;
}



std::istream& operator>>(std::istream& is, PassengerTrain& passenger_train){
	is >> passenger_train._year >> passenger_train._weight >> passenger_train.max_speed >> passenger_train._wagons;

	char buffer[BUFFER_SIZE];

	is >> buffer;
	copyString(passenger_train._driver, buffer);

	is >> passenger_train._passengers;
	
	return is;

}




