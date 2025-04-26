#pragma once
#include "Product.h"
#include "Restaurant.h"

size_t roundToPowerOfTwo(size_t num);
size_t dataToAlloc(size_t size);
void copyString(char*& dest, const char* src);
void copyProducts(Product*& dest, const Product* src, size_t size);
void copyRestaurants(Restaurant*& dest, const Restaurant* src, size_t size);
void readString(std::istream& is, char*& dest);
