#pragma once
#include <iostream>

class MultiSet {
public:
	MultiSet() = default;
	MultiSet(size_t n, size_t k);
	MultiSet(const MultiSet& other);
	MultiSet& operator=(const MultiSet& other);
	~MultiSet();

	void add(uint16_t num);
	uint16_t count(uint16_t num) const;
	void print() const;
	void serialize(const char* filename);
	void deserialize(const char* filename);

	MultiSet intersection(const MultiSet& other) const;
	MultiSet difference(const MultiSet& other) const;

private:
	size_t n;
	size_t k;
	uint8_t* bitset;

	size_t getByteSize() const;
	void copyFrom(const MultiSet& other);
	void free();
	void getBitPosition(uint16_t num, size_t& byteIndex, uint8_t& bitOffset) const;

};