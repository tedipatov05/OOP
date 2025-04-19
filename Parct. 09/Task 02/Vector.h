#pragma once

class Vector{
public:

	Vector();
	Vector(unsigned size, const int& initialValue);
	Vector(const Vector& vector);
	Vector(unsigned capacity);
	Vector& operator=(const Vector& vector);
	~Vector();

	void pushBack(const int& value);
	void popBack();
	bool isEmpty() const;
	void reserve(unsigned newCapacity);
	void shrinkToFit();
	void clear();

	const int& operator[](unsigned index) const;
	int& operator[](unsigned index);

	const int& at(unsigned index) const;
	int& at(unsigned index);

	void removeAt(unsigned index);
	void insertAt(unsigned index, const int& value);

	const int* getData() const;
	unsigned getSize() const;
	unsigned getCapacity() const;

private:
	int* _data;
	unsigned size;
	unsigned capacity;

	void copyDynamic(const Vector& vector);
	void freeDynamic();
	void copyInts(int*& dest, const int* source, unsigned size);
	
};

bool operator==(const Vector& lhs, const Vector& rhs);
