#pragma once

class NumbersWriter
{
public:
	virtual void write(const int* numbers, size_t size) const = 0;
};
