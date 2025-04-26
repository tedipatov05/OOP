#include "Restaurant.h"
#include <algorithm>
#include "Utils.h"
#include "Constants.h"

Restaurant::Restaurant() : _size(0), _capacity(dataToAlloc(INITIAL_CAPACITY)){
	this->_name = new char[INITIAL_CAPACITY];
	this->_products = new Product[this->_capacity];
}

Restaurant::Restaurant(const char* name, size_t productsCapacity) : _size(0), _capacity(productsCapacity){
	copyString(this->_name, name);
	this->_products = new Product[productsCapacity];
}

Restaurant::Restaurant(const Restaurant& restaurant){
	copyDynamic(restaurant);
	this->_capacity = restaurant.capacity();
	this->_size = restaurant.size();
}

Restaurant::Restaurant(const char* name, const Product* products, size_t size) : _size(size), _capacity(dataToAlloc(size)){
	this->_products = new Product[capacity()];
	copyProducts(this->_products, products, size);
}

void Restaurant::copyMove(Restaurant&& restaurant){
	this->_name = restaurant._name;
	restaurant._name = nullptr;
	this->_products = restaurant._products;
	restaurant._products = nullptr;
	this->_capacity = restaurant.capacity();
	this->_size = restaurant.size();
}

Restaurant::Restaurant(Restaurant&& restaurant) noexcept{
	copyMove(std::move(restaurant));
}

Restaurant& Restaurant::operator=(Restaurant&& restaurant) noexcept{
	if (this != &restaurant){
		free();
		copyMove(std::move(restaurant));
	}

	return *this;
}

Restaurant& Restaurant::operator=(const Restaurant& restaurant){
	if (this != &restaurant){
		free();
		copyDynamic(restaurant);
		this->_size = restaurant.size();
		this->_capacity = restaurant.capacity();
	}

	return *this;
}

size_t Restaurant::capacity() const{
	return this->_capacity;
}

size_t Restaurant::size() const{
	return this->_size;
}

void Restaurant::resize(size_t newCapacity){
	Product* temp = new Product[newCapacity];
	copyProducts(temp, this->_products, this->size());
	delete[] this->_products;
	this->_products = temp;
}

void Restaurant::addProduct(const Product& product) {
	if (this->_size >= this->_capacity) {
		this->resize(this->_capacity * 2);
	}

	this->_products[this->_size] = product;
	this->_size++;
}

void Restaurant::addProduct(Product&& product) {
	if (this->_size >= this->_capacity) {
		this->resize(this->_capacity * 2);
	}

	this->_products[this->_size] = std::move(product);
	this->_size++;
}

Restaurant::~Restaurant(){
	free();
}

const char* Restaurant::name() const{
	return this->_name;
}

const Product* Restaurant::products() const{
	return this->_products;
}

bool Restaurant::contains(const Product& product) {
	for (size_t i = 0; i < this->size(); i++){
		if (this->products()[i] == product){
			return true;
		}
	}

	return false;
}


void Restaurant::free(){
	delete[] _name;
	delete[] _products;
	this->_size = -1;
	this->_capacity = 0;
}

void Restaurant::copyDynamic(const Restaurant& restaurant){
	copyString(this->_name, restaurant._name);

	this->_products = new Product[restaurant.capacity()];
	copyProducts(this->_products, restaurant._products, restaurant.size());
}

unsigned Restaurant::order(const Order& order){
	if (order.size() == 0){
		throw std::invalid_argument("Invalid order");
	}

	for (size_t i = 0; i < order.size(); i++){
		if (!this->contains(order.products()[i])){
			throw std::invalid_argument("Some products are currently out of stock");
		}
	}

	return order.size() * 10;
	
}





