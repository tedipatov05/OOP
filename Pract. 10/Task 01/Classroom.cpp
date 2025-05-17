#include "Classroom.h"

namespace {
	constexpr int INITIAL_CAPACITY = 8;

	unsigned roundToPowerOfTwo(unsigned v)
	{
		v--;
		v |= v >> 1;
		v |= v >> 2;
		v |= v >> 4;
		v |= v >> 8;
		v |= v >> 16;
		v++;
		return v;
	}

	void setStudents(Student**& dest, const Student** src, int count) {
		for (size_t i = 0; i < count; i++) {
			dest[i] = new Student(*src[i]);
		}
	}

}


Classroom::Classroom() {
	this->_students = new Student * [INITIAL_CAPACITY] {nullptr};
	this->_capacity = INITIAL_CAPACITY;
	this->_size = 0;
}

Classroom::Classroom(const Student** students, int count) : _capacity(roundToPowerOfTwo(count)), _size(count) {
	this->_students = new Student * [this->_capacity];
	setStudents(this->_students, students, count);
}

Classroom::Classroom(const Classroom& classroom) : _size(classroom._size), _capacity(classroom._capacity) {
	copyDynamic(classroom);
}

Classroom::Classroom(Classroom&& classroom) noexcept : _size(classroom._size), _capacity(classroom._capacity) {
	moveDynamic(std::move(classroom));
}

Classroom& Classroom::operator=(const Classroom& classroom) {
	if (this != &classroom) {
		free();
		copyDynamic(classroom);
		this->_size = classroom._size;
		this->_capacity = classroom._capacity;
	}

	return *this;
}

Classroom& Classroom::operator=(Classroom&& classroom) noexcept {
	if (this != &classroom) {
		free();
		moveDynamic(std::move(classroom));
		this->_size = classroom._size;
		this->_capacity = classroom._capacity;

	}

	return *this;
}

Classroom::~Classroom() {
	free();
}

int Classroom::freeSpaces() const {
	return this->_capacity - this->_size;
}

void Classroom::suspendStudent(int index) {
	delete _students[index];
	for (int i = index; i < _size - 1; i++) {
		_students[i] = _students[i + 1];
	}
	_students[--_size] = nullptr;
}

void Classroom::swapStudents(int index1, int index2) {

	Student* temp = _students[index1];
	_students[index1] = _students[index2];
	_students[index2] = temp;
}

void Classroom::addStudent(const Student& student){
	if (this->_size == this->_capacity){
		resize(this->_capacity * 2);
	}

	this->_students[this->_size++] = new Student(student);
}

void Classroom::addStudent(Student&& student){
	if (this->_size == this->_capacity) {
		resize(this->_capacity * 2);
	}

	this->_students[this->_size++] = new Student(std::move(student));
}

int Classroom::getEmptiestRow(int count) const{
	int numRows = (_capacity + count - 1) / count;
	int minFilled = count + 1;
	int minRow = 0;

	for (int row = 0; row < numRows; row++) {
		int filledInRow = 0;
		for (int i = 0; i < count; i++) {
			int index = row * count + i;
			if (index < _size) filledInRow++;
		}
		if (filledInRow < minFilled) {
			minFilled = filledInRow;
			minRow = row;
		}
	}
	return minRow;
}

int Classroom::capacity() const{
	return this->_capacity;
}

int Classroom::size() const{
	return this->_size;
}





void Classroom::copyDynamic(const Classroom& room) {
	this->_students = new Student * [room._capacity] {nullptr};
	setStudents(this->_students, (const Student**)room._students, room._size);
}

void Classroom::moveDynamic(Classroom&& room) {
	this->_students = room._students;
	room._students = nullptr;
}

void Classroom::free() {
	for (size_t i = 0; i < _size; i++) {
		delete _students[i];
	}

	delete[] _students;
}

void Classroom::resize(int capacity) {

	Student** temp = new Student * [capacity] {nullptr};
	setStudents(temp, (const Student**)this->_students, this->_size);

	free();

	this->_students = temp;
	this->_capacity = capacity;
}




