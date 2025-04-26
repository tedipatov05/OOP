#include "FoodPanda.h"

#include "Utils.h"
#include "Constants.h"

FoodPanda::FoodPanda() : _size(0), _capacity(INITIAL_CAPACITY){
	this->_restaurants = new Restaurant[INITIAL_CAPACITY];
}

FoodPanda::FoodPanda(size_t capacity) : _size(0), _capacity(dataToAlloc(capacity)) {
	this->_restaurants = new Restaurant[this->capacity()];
}

FoodPanda::FoodPanda(Restaurant* restaurants, size_t size) : _size(size), _capacity(dataToAlloc(size)){
	this->_restaurants = new Restaurant[this->capacity()];
	copyRestaurants(this->_restaurants, restaurants, size);
}

FoodPanda::FoodPanda(const FoodPanda& other) : _size(other.size()), _capacity(other.capacity()){
	copyDynamic(other);
}

FoodPanda::FoodPanda(FoodPanda&& other) noexcept : _size(other.size()), _capacity(other.capacity()){
	copyMove(std::move(other));
}

FoodPanda& FoodPanda::operator=(const FoodPanda& food_panda){
	if (this != &food_panda){
		free();
		copyDynamic(food_panda);
		this->_capacity = food_panda.capacity();
		this->_size = food_panda.size();
	}

	return *this;
}

FoodPanda& FoodPanda::operator=(FoodPanda&& food_panda) noexcept{
	if (this != &food_panda){
		free();
		this->_capacity = food_panda.capacity();
		this->_size = food_panda.size();
		copyMove(std::move(food_panda));
		
	}

	return *this;
}

size_t FoodPanda::size() const{
	return this->_size;
}

size_t FoodPanda::capacity() const{
	return this->_capacity;
}



FoodPanda::~FoodPanda(){
	free();
}

void FoodPanda::resize(size_t newCap){
	this->_capacity = dataToAlloc(newCap);

	Restaurant* temp = new Restaurant[this->capacity()];
	copyRestaurants(temp, this->_restaurants, this->size());
	delete[] this->_restaurants;
	this->_restaurants = temp;
}

void FoodPanda::addRestaurant(const Restaurant& restaurant){
	if (this->size() == this->capacity()){
		resize(this->capacity() * 2);
	}

	this->_restaurants[this->_size++] = restaurant;
}

void FoodPanda::addRestaurant(Restaurant&& restaurant){
	if (this->size() == this->capacity()) {
		resize(this->capacity() * 2);
	}

	this->_restaurants[this->_size++] = std::move(restaurant);
}

int FoodPanda::assignOrder(const Order& order) const{
	for (size_t i = 0; i < this->size(); i++){
		if (std::strcmp(this->_restaurants[i].name(), order.restaurant()) == 0){
			return this->_restaurants[i].order(order);
		}
	}

	return -1;
}


void FoodPanda::readOrders(std::istream& is) {

	size_t size = 0;

	is >> size;
	is.ignore();
	Order* orders = new Order[size];

	for (size_t i = 0; i < size; i++){
		is >> orders[i];

		try{
			int deliveryTime = assignOrder(orders[i]);

			deliveryTime != -1 ? std::cout << "Your order will be delivered in: " << deliveryTime << std::endl
				: std::cout << "This restaurant does not exist" << std::endl;
			
		}catch (std::invalid_argument ex){
			std::cout << ex.what();
		}

		
	}

}




void FoodPanda::free(){
	delete[] this->_restaurants;
	this->_size = -1;
	this->_capacity = 0;
}



void FoodPanda::copyDynamic(const FoodPanda& food_panda){
	this->_restaurants = new Restaurant[food_panda.capacity()];
	copyRestaurants(this->_restaurants, food_panda._restaurants, food_panda.size());
}

void FoodPanda::copyMove(FoodPanda&& food_panda){
	this->_restaurants = food_panda._restaurants;
	food_panda._restaurants = nullptr;
}


