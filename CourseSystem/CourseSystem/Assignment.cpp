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

void Assignment::writeToBinaryFile(std::ofstream& ofs) const {
	this->_taskName.writeToBinaryFile(ofs);
	this->_description.writeToBinaryFile(ofs);

	size_t size = this->_submissions.size();
	ofs.write((const char*)(&size), sizeof(size));
	for (size_t i = 0; i < size; ++i) {
		this->_submissions[i].writeToBinaryFile(ofs);
	}
}

void Assignment::readFromBinaryFile(std::ifstream& ifs) {
	this->_taskName.readFromBinaryFile(ifs);
	this->_description.readFromBinaryFile(ifs);

	size_t size = 0;
	ifs.read((char*)(&size), sizeof(size));
	
	for (size_t i = 0; i < size; ++i) {
		Submission submission;
		submission.readFromBinaryFile(ifs);
		this->_submissions.push_back(submission);
	}
}
