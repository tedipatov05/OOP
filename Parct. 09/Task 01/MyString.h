#pragma once
#include <ostream>

class MyString {
public:

	MyString();
	MyString(const char* str);
	MyString(const MyString& str);
	MyString& operator=(const MyString& str);
	~MyString();

	unsigned getSize() const;
	unsigned getCapacity() const;
	const char* getString() const;

	char& operator[](unsigned index);
	const char& operator[](unsigned index) const;
	MyString& operator+=(const MyString& str);
	friend std::ostream& operator<<(std::ostream& os, const MyString& str);
	friend std::istream& operator>>(std::istream& is, MyString& str);
	friend MyString operator+(const MyString& lhs, const MyString& rhs);



private:
	char* _data;
	unsigned capacity;


	void copyDynamic(const MyString& other);
	void freeDynamic();
	void copyString(char*& dest, const char* src, unsigned capacity) const;

	void resize(unsigned newCapacity);

};


bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);
bool operator<(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);

