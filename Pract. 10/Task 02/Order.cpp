#include "Order.h"
#include <sstream>

#include "Utils.h"
#include "Constants.h"



Order::Order(){
	this->_size = 0;
	this->_capacity = INITIAL_CAPACITY;
	this->restaurantName = new char[INITIAL_CAPACITY] {'\0'};
	this->_products = new Product[this->_capacity];
}

Order::Order(const char* restaurantName, const Product* products, size_t size) : _size(size), _capacity(dataToAlloc(size)) {
	this->_products = new Product[this->_capacity];
	copyProducts(this->_products, products, size);
	copyString(this->restaurantName, restaurantName);
}
Order::Order(const Order& order) : _capacity(order.capacity()), _size(order.size()) {
	copyDynamic(order);

}

Order& Order::operator=(const Order& order){
	if (this != &order){
		free();
		copyDynamic(order);
		this->_capacity = order.capacity();
		this->_size = order.size();
	}

	return *this;
}

Order& Order::operator=(Order&& order) noexcept{
	if (this != &order){
		free();
		copyMove(std::move(order));
	}

	return *this;
}



Order::Order(Order&& order) noexcept{
	this->_size = order.size();
	this->_capacity = order.capacity();
	copyMove(std::move(order));

}

Order::~Order(){
	free();
}


void Order::free(){
	delete[] this->restaurantName;
	delete[] this->_products;
	this->_size = -1;
	this->_capacity = 0;
}


void Order::copyDynamic(const Order& order) {
	copyString(this->restaurantName, order.restaurantName);
	this->_products = new Product[order.capacity()];
	copyProducts(this->_products, order.products(), order.size());
}

void Order::copyMove(Order&& order){
	this->restaurantName = order.restaurantName;
	order.restaurantName = nullptr;
	this->_products = order._products;
	order._products = nullptr;
}

size_t Order::capacity() const{
	return this->_capacity;
}
size_t Order::size() const{
	return this->_size;
}

const char* Order::restaurant() const{
	return this->restaurantName;
}

const Product* Order::products() const{
	return this->_products;
}

std::istream& operator>>(std::istream& is, Order& order){
	readString(is, order.restaurantName);

	size_t size = 0;
	is >> size;

	is.ignore();

	if (size > order.capacity()){
		order.resize(dataToAlloc(size));
		order._capacity = dataToAlloc(size);
	}
	order._size = size;

	char buffer[BUFFER_SIZE];
	is.getline(buffer, BUFFER_SIZE);
	std::stringstream sstream(buffer);

	for (size_t i = 0; i < order.size(); i++){
		sstream >> order._products[i];
	}

	return is;

}

void Order::resize(size_t newCap){
	this->_capacity = dataToAlloc(newCap);

	Product* temp = new Product[this->capacity()];
	copyProducts(temp, this->products(), this->size());
	delete[] this->_products;
	this->_products = temp;
}








