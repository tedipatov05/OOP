#include "Course.h"

Course::Course(){
	
}

Course::Course(const MyString& courseName, const MyString& courseDescription, const MyString& password) {
	//this->_userRepository = new UserRepository();
	this->_courseName = courseName;
	this->_courseDescription = courseDescription;
	this->_password = password;
}

void Course::addParticipant(const User* user) {
	this->_userRepository.addUser(user);
}

const MyString Course::getCourseName() const {
	return this->_courseName;
}


