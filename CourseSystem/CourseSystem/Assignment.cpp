#include "Assignment.h"

#include <iostream>



Assignment::Assignment(const MyString& taskName, const MyString& description) {
	this->_taskName = taskName;
	this->_description = description;
}

void Assignment::print() const {
	std::cout << " | " << _taskName << " | Description: " << _description << std::endl;
}

const MyString& Assignment::getTaskName() const {
	return this->_taskName;
}

void Assignment::addSubmission(const Submission& submission) {
	this->_submissions.push_back(submission);
}
