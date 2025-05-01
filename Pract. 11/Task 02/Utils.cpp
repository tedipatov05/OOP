#include <algorithm>
#include "Constants.h"
#include "Utils.h"
#pragma warning(disable:4996)

size_t roundToPowerOfTwo(size_t num) {
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

void setString(char*& dest, const char* src){
	size_t len = strlen(src);
	dest = new char[len + 1];
	strcpy(dest, src);
}
