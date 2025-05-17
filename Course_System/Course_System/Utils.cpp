#include "Utils.h"
#include <iostream>
#pragma warning(disable:4996)


void setString(char*& dest, const char* src){
	size_t len = strlen(src);
	dest = new char[len + 1];
	strcpy(dest, src);
}

size_t roundToPowerOfTwo(size_t v)
{
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;
}

