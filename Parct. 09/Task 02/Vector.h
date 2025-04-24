#pragma once

class Vector{
public:

	Vector();
	Vector(size_t size, const int& initialValue);
	Vector(const Vector& vector);
	Vector(size_t capacity);
	Vector& operator=(const Vector& vector);
	~Vector();

	void push_back(const int& value);
	void pop_back();
	bool is_empty() const;
	void reserve(size_t newCapacity);
	void shrink_to_fit();
	void clear();

	const int& operator[](size_t index) const;
	int& operator[](size_t index);

	const int& at(size_t index) const;
	int& at(size_t index);

	void remove_at(size_t index);
	void insert_at(size_t index, const int& value);
	void insert_range(size_t index, const int* values, size_t size);
	void swap(Vector& other);

	const int* data() const;
	size_t size() const;
	size_t capacity() const;

private:
	int* _data;
	size_t _size;
	size_t _capacity;

	void copyDynamic(const Vector& vector);
	void freeDynamic();
	void copyInts(int*& dest, const int* source, size_t size);
	
};

bool operator==(const Vector& lhs, const Vector& rhs);
bool operator!=(const Vector& lhs, const Vector& rhs);
bool operator<(const Vector& lhs, const Vector& rhs);
bool operator>(const Vector& lhs, const Vector& rhs);
bool operator<=(const Vector& lhs, const Vector& rhs);
bool operator>=(const Vector& lhs, const Vector& rhs);
