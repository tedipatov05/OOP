#pragma once
#include "Restaurant.h"

class FoodPanda
{
public:

	FoodPanda();
	FoodPanda(size_t capacity);
	FoodPanda(Restaurant* restaurants, size_t size);
	FoodPanda(const FoodPanda& other);
	FoodPanda(FoodPanda&& other) noexcept;
	FoodPanda& operator=(const FoodPanda& food_panda);
	FoodPanda& operator=(FoodPanda&& food_panda) noexcept;
	~FoodPanda();

	void addRestaurant(const Restaurant& restaurant);
	void addRestaurant(Restaurant&& restaurant);

	void readOrders(std::istream& stream);

	size_t size() const;
	size_t capacity() const;

private:

	Restaurant* _restaurants;
	size_t _size;
	size_t _capacity;

	void copyDynamic(const FoodPanda& food_panda);
	void copyMove(FoodPanda&& food_panda);
	void free();

	int assignOrder(const Order& order) const;

	void resize(size_t newCap);
};
