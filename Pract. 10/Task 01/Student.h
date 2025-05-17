#pragma once
#include <iostream>

class Student{

public:
	Student();
	Student(const char* name, int faculty_number);
	Student(const Student& student);
	Student(Student&& student) noexcept;

	Student& operator=(const Student& other);
	Student& operator=(Student&& other) noexcept;

	const char* name() const;

	~Student();


private:

	char* _name;
	int faculty_number;

	void copyDynamic(const Student& other);
	void moveDynamic(Student&& other);
	void free();
};

