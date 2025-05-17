#include "Assignment.h"


Assignment::Assignment(const Course& course, const MyString& taskName, const MyString& description){
	this->_course = course;
	this->_taskName = taskName;
	this->_description = description;
}

void Assignment::print() const {
	std::cout << _course.getCourseName() << " | " << _taskName << " | Description: " << _description << std::endl;
}

const MyString& Assignment::getTaskName() const {
	return _taskName;
}



