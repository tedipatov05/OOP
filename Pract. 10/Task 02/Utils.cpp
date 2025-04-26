#include "Utils.h"
#include "Constants.h"
#include <algorithm>
#pragma warning(disable:4996)


size_t roundToPowerOfTwo(size_t num){
	num--;
	num |= num >> 1;
	num |= num >> 2;
	num |= num >> 4;
	num |= num >> 8;
	num |= num >> 16;
	num++;
	return num;
	
}

size_t dataToAlloc(size_t size)
{
	return std::max(roundToPowerOfTwo(size + 1), INITIAL_CAPACITY);
}

void copyString(char*& dest, const char* src) {
	size_t len = std::strlen(src);
	dest = new char[len + 1];
	std::strcpy(dest, src);
	dest[len] = '\0';
}

void copyProducts(Product*& dest, const Product* src, size_t size) {
	for (size_t i = 0; i < size; i++) {
		dest[i] = src[i];
	}
}

void copyRestaurants(Restaurant*& dest, const Restaurant* src, size_t size){
	for (size_t i = 0; i < size; i++){
		dest[i] = src[i];
	}
}

void readString(std::istream& is, char*& dest){
	char buffer[BUFFER_SIZE];
	is.getline(buffer, BUFFER_SIZE, ' ');

	char* temp;
	copyString(temp, buffer);
	delete[] dest;
	dest = temp;
}




