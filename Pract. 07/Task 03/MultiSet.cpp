#include "MultiSet.h"
#include <iostream>
#include <fstream>

MultiSet::MultiSet(size_t bitCount, size_t maxNum) : k(bitCount), n(maxNum) {
	this->bitset = new uint8_t[getByteSize()];
}

void MultiSet::getBitPosition(uint16_t num, size_t& byteIndex, uint8_t& bitOffset) const {
	size_t bitPos = num * k;
	byteIndex = bitPos / 8;
	bitOffset = bitPos % 8;
}

MultiSet::~MultiSet() {
	free();
}

void MultiSet::add(uint16_t num) {
	if (num > n) {
		return;
	}

	size_t byteIndex;
	uint8_t bitOffset;
	getBitPosition(num, byteIndex, bitOffset);

	uint16_t count = (bitset[byteIndex] >> bitOffset) & ((1 << k) - 1);
	if (count < (1 << k) - 1) {
		count++;
		bitset[byteIndex] &= ~(((1 << k) - 1) << bitOffset);
		bitset[byteIndex] |= (count << bitOffset);
	}
}

uint16_t MultiSet::count(uint16_t num) const {
	if (num > n) return 0;
	size_t byteIndex;
	uint8_t bitOffset;
	getBitPosition(num, byteIndex, bitOffset);
	return (bitset[byteIndex] >> bitOffset) & ((1 << k) - 1);
}

size_t MultiSet::getByteSize() const {
	return ((n + 1) * k + 7) / 8;
}

void MultiSet::free() {
	delete[] this->bitset;
}


void MultiSet::serialize(const char* filename) {
	std::ofstream ofs(filename, std::ios::binary);

	if (!ofs.is_open()) {
		return;
	}

	size_t len = getByteSize();

	ofs.write((const char*)&len, sizeof(len));
	ofs.write((const char*)this->bitset, len * sizeof(uint8_t));

}

void MultiSet::deserialize(const char* filename) {

}
