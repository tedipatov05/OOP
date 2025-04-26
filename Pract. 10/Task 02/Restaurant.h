#pragma once
#include "Product.h"
#include "Order.h"

class Restaurant
{
public:
	Restaurant();
	Restaurant(const char* name, size_t productsCapacity);
	Restaurant(const char* name, const Product* products, size_t size);
	Restaurant(const Restaurant& restaurant);
	Restaurant(Restaurant&& restaurant) noexcept;
	Restaurant& operator=(const Restaurant& restaurant);
	Restaurant& operator=(Restaurant&& restaurant) noexcept;
	~Restaurant();

	size_t capacity() const;
	size_t size() const;
	const char* name() const;
	const Product* products() const;

	void addProduct(const Product& product);
	void addProduct(Product&& product);

	unsigned order(const Order& order);

private:

	char* _name;
	Product* _products;
	size_t _size;
	size_t _capacity;

	void free();
	void copyDynamic(const Restaurant& restaurant);
	void copyMove(Restaurant&& restaurant);

	bool contains(const Product& product);

	void resize(size_t newCapacity);

};
