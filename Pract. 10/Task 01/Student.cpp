#include "Student.h"
#pragma warning(disable:4996)

namespace 
{
	constexpr int INITIAL_SIZE = 8;

	void setString(char*& dest, const char* src){
		if (!src){
			return;
		}

		size_t len = strlen(src);
		dest = new char[len + 1];
		strcpy(dest, src);
	}
}

Student::Student() {
	this->_name = new char[8] {'\0'};
	this->faculty_number = 0;
}

Student::Student(const char* name, int faculty_number) : faculty_number(faculty_number){
	setString(this->_name, name);
}

Student::Student(const Student& student) : faculty_number(student.faculty_number){
	copyDynamic(student);
}

Student::Student(Student&& student) noexcept : faculty_number(student.faculty_number){
	moveDynamic(std::move(student));
}

Student& Student::operator=(const Student& other){
	if (this != &other){
		free();
		copyDynamic(other);
		this->faculty_number = other.faculty_number;
	}

	return *this;
}

Student& Student::operator=(Student&& other) noexcept{
	if (this != &other){
		free();
		moveDynamic(std::move(other));
		this->faculty_number = other.faculty_number;
	}

	return *this;
}

Student::~Student(){
	free();
}

const char* Student::name() const{
	return this->_name;
}

void Student::copyDynamic(const Student& other){
	setString(this->_name, other._name);
}

void Student::moveDynamic(Student&& other){
	this->_name = other._name;
	other._name = nullptr;
}

void Student::free() {
	delete[] this->_name;
}



