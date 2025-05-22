#include "Course.h"


Course::Course(const MyString& courseName, const MyString& password) {
	this->_courseName = courseName;
	this->_password = password;
}

void Course::addParticipant(const User* user) {
	this->users.push_back(user->getId());
}

void Course::addAssignment(const Assignment& assignment) {
	this->_assignments.push_back(assignment);
}

const MyString Course::getCourseName() const {
	return this->_courseName;
}

void Course::writeToBinaryFile(std::ofstream& ofs) const {
	size_t sizeUsers = this->users.size();
	ofs.write((const char*)(&sizeUsers), sizeof(sizeUsers));
	for (size_t i = 0; i < sizeUsers; ++i) {
		ofs.write((const char*)(&this->users[i]), sizeof(this->users[i]));
	}

	this->_courseName.writeToBinaryFile(ofs);
	this->_password.writeToBinaryFile(ofs);

	size_t size = this->_assignments.size();
	ofs.write((const char*)(&size), sizeof(size));
	for (size_t i = 0; i < size; ++i) {
		this->_assignments[i].writeToBinaryFile(ofs);
	}
}

void Course::readFromBinaryFile(std::ifstream& ifs){
	size_t sizeUsers = 0;
	ifs.read((char*)(&sizeUsers), sizeof(sizeUsers));
	for (size_t i = 0; i < sizeUsers; ++i) {
		int userId = 0;
		ifs.read((char*)(&userId), sizeof(userId));
		this->users.push_back(userId);
	}

	this->_courseName.readFromBinaryFile(ifs);
	this->_password.readFromBinaryFile(ifs);

	size_t size = 0;
	ifs.read((char*)(&size), sizeof(size));

	for (size_t i = 0; i < size; ++i) {
		Assignment assignment;
		assignment.readFromBinaryFile(ifs);
		this->_assignments.push_back(assignment);
	}
}


