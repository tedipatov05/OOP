#include "FreightTrain.h"
#include "../Task 02/Constants.h"
#include "Utils.h"

FreightTrain::FreightTrain() : Train(), depot_number(0){
	
}

FreightTrain::FreightTrain(size_t year, size_t weight, size_t maxSpeed, size_t wagons, const char* driver, unsigned depotNumber)
	: Train(year, weight, maxSpeed, wagons, driver), depot_number(depotNumber){
	
}

unsigned FreightTrain::depotNumber() const{
	return this->depot_number;
}

std::ostream& operator<<(std::ostream& os, const FreightTrain& freight_train){

	os << freight_train.year() << " " << freight_train.weight() << " " << freight_train.maxSpeed() << " " << freight_train.wagons()
		<< " " << freight_train.driver() << " " << freight_train.depotNumber();

	return os;
}

std::istream& operator>>(std::istream& is, FreightTrain& freight_train){
	is >> freight_train._year >> freight_train._weight >> freight_train.max_speed >> freight_train._wagons;

	char buffer[BUFFER_SIZE];

	is >> buffer;
	copyString(freight_train._driver, buffer);

	is >> freight_train.depot_number;

	return is;
}




