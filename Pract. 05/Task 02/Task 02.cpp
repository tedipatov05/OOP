// Task 02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#pragma warning(disbale:4996)

class Trailer {

public:

	Trailer() = default;

	Trailer(double maxCapacity, double area, double currentLoad) {

		setMaxCapacity(maxCapacity);
		setArea(area);
		setCurrentLoad(currentLoad);

	}

	void setMaxCapacity(double maxCapacity) {
		if (maxCapacity < 0) {
			return;
		}

		this->maxCapacity = maxCapacity;
	}

	void setArea(double area) {

		if (area < 0)
		{
			return;
		}
		this->area = area;
	}

	void setCurrentLoad(double currentLoad) {
		if (currentLoad < 0)
		{
			return;
		}
		this->currentLoad = currentLoad;
	}

	double getMaxCapacity() const {
		return this->maxCapacity;
	}

	double getArea() const {
		return this->area;
	}

	double getCurrentLoad() const {
		return this->currentLoad;
	}

	void addLoad(double weight) {
		if ((getCurrentLoad() + weight) <= maxCapacity) {

			setCurrentLoad(getCurrentLoad() + weight);
		}
	}


private:

	double maxCapacity;
	uint32_t area;
	double currentLoad;

};

class Engine {
public:

	Engine() = default;

	Engine(uint32_t horsePower, double fuelExpense, double reservoirVolume, double currentFuel) {
		setHorsePower(horsePower);
		setFuelExpense(fuelExpense);
		setReservoirVolume(reservoirVolume);
		setCurrentFuel(currentFuel);
	}

	void setHorsePower(uint32_t horsePower) {
		this->horsePower = horsePower;
	}

	void setFuelExpense(double fuelExpense) {
		this->fuelExpense = fuelExpense;
	}

	void setReservoirVolume(double reservoirVolume) {
		this->reservoirVolume = reservoirVolume;
	}

	void fuel(double liters) {
		if ((getCurrentFuel() + liters) < reservoirVolume) {

			setCurrentFuel(currentFuel + liters);
		}
	}

	void drive(double km) {
		double fuel = getCurrentFuel();
		double expectedExpense = (km * 0.01) * getFuelExpense();

		if (expectedExpense > fuel)
		{
			std::cout << "Do not have enough fuel" << std::endl;
		}

		setCurrentFuel(fuel - expectedExpense);

	}

	double getRemainingRange() const {
		return (currentFuel * 100) / fuelExpense;
	}



	uint32_t getHorsePower() const {
		return this->horsePower;
	}

	double getFuelExpense() const {
		return this->fuelExpense;
	}

	double getReservoirVolume() const {
		return this->reservoirVolume;
	}

	double getCurrentFuel() const {
		return this->currentFuel;
	}



private:

	uint32_t horsePower;
	double fuelExpense;
	double reservoirVolume;
	double currentFuel;

	void setCurrentFuel(double currentFuel) {
		if (currentFuel < 0) {
			return;
		}
		this->currentFuel = currentFuel;

	}

};

class Truck {

	Truck(){
		setBrand("Default truck");
		trailer = nullptr;
	}

	Truck(const char* brand, double weight, Engine* engine, Trailer* trailer){
		setBrand(brand);
		setWeight(weight);
		setEngine(engine);
		setTrailer(trailer);

	}

	void setBrand(const char* brand) {

		if (!brand){
			return;
		}

		size_t size = strlen(brand) + 1;

		if (size == 1){
			return;
		}

		this->brand = new char[size];
		strcpy(this->brand, brand);

	}

	void setWeight(double weight) {
		this->weight = weight;
	}


	const char* getBrand() const{
		return this->brand;
	}

	double getWeight() const{
		return this->weight;
	}

	const Engine* getEngine() const {
		return this->engine;
	}

	const Trailer* getTrailer() const {
		return this->trailer;
	}

	void attachTrailer(Trailer* trailer){
		delete this->trailer;
		setTrailer(trailer);
	}

	bool hasTrailer() const {
		return !trailer;
	}

	void detachTrailer(){
		delete trailer;
		setTrailer(nullptr);
	}

	void drive(double km) {
		this->engine->drive(km);
	}

	void loadTruck(double weight) {
		if (!hasTrailer()){
			return;
		}
		this->trailer->addLoad(weight);
	}

	void changeEngine(Engine* engine){

		delete this->engine;
		setEngine(engine);
		
	}

	~Truck() {
		delete[] brand;
		delete trailer;
		delete engine;
	}

private:
	char* brand = nullptr;
	double weight = 0;

	Engine* engine = nullptr;
	Trailer* trailer = nullptr;


	void setTrailer(Trailer* trailer) {
		this->trailer = trailer;
	}

	void setEngine(Engine* engine) {
		this->engine = engine;
	}

};

int main()
{
	std::cout << "Hello World!\n";
}

