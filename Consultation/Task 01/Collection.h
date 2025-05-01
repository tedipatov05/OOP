#pragma once
#include "NumbersWriter.h"

class Collection{

public:

	Collection(const int* numbers, size_t size);
	virtual void add(int number) = 0;
	virtual void remove(int number) = 0;
	virtual size_t getSize() const = 0;
	virtual bool contains(int number) const = 0;
	void print(NumbersWriter* numbers_writer) const;

	virtual ~Collection(){
		delete[] numbers;
	}

protected:

	int* numbers = nullptr;
	size_t size;
	Collection() = default;

private:
	void copy(const int* numbers, size_t size);
};

