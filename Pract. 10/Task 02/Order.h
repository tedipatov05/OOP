#pragma once
#include <iostream>
#include "Product.h"


class Order
{
public:
	Order();
	Order(const char* restaurantName, const Product* products, size_t size);
	Order(const Order& order);
	Order(Order&& order) noexcept;
	Order& operator=(const Order& order);
	Order& operator=(Order&& order) noexcept;
	~Order();

	size_t capacity() const;
	size_t size() const;
	const char* restaurant() const;
	const Product* products() const;

	friend std::istream& operator>>(std::istream& is, Order& order);
private:
	char* restaurantName;
	Product* _products;
	size_t _size;
	size_t _capacity;

	void free();
	void copyDynamic(const Order& order);
	void copyMove(Order&& order);

	void resize(size_t newCap);

};
