#include "CourseRepository.h"
#include "Constants.h"

CourseRepository::CourseRepository(){
	this->_size = 0;
	this->_capacity = INITIAL_SIZE;
	this->_courses = new Course[this->_capacity];
}

CourseRepository::CourseRepository(const CourseRepository& other){
	copyDynamicMemory(other);
	this->_size = other._size;
	this->_capacity = other._capacity;
}

CourseRepository& CourseRepository::operator=(const CourseRepository& other){
	if (this != &other) {
		free();
		copyDynamicMemory(other);
		this->_size = other._size;
		this->_capacity = other._capacity;
	}
	return *this;
}

CourseRepository::~CourseRepository(){
	free();
}

void CourseRepository::addCourse(const Course& course){
	if (this->_size == this->_capacity){
		resize();
	}

	this->_courses[this->_size] = course;
	this->_size++;
}

void CourseRepository::removeCourse(int index){
	if (index < 0 || index >= this->_size) {
		throw std::out_of_range("Invalid index");
	}

	for (size_t i = index; i < this->_size - 1; i++) {
		this->_courses[i] = this->_courses[i + 1];
	}

	this->_size--;
}

const Course& CourseRepository::getCourse(int index) const
{
	return this->_courses[index];
}

int CourseRepository::getSize() const
{
	return this->_size;
}

void CourseRepository::copyDynamicMemory(const CourseRepository& other) {
	this->_courses = new Course[other._capacity];
	for (size_t i = 0; i < other._size; i++) {
		this->_courses[i] = other._courses[i];
	}
}

void CourseRepository::free(){
	delete[] this->_courses;
}

void CourseRepository::resize(){
	this->_capacity *= 2;
	Course* new_courses = new Course[this->_capacity];

	for (size_t i = 0; i < this->_size; i++){
		new_courses[i] = this->_courses[i];
	}

	delete[] this->_courses;
	this->_courses = new_courses;
}

