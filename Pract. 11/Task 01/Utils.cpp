#include "Utils.h"
#include <cstring>
#pragma warning(disable:4996)

void copyString(char*& dest, const char* src){

	size_t len = strlen(src);
	dest = new char[len + 1];
	strcpy(dest, src);
}
