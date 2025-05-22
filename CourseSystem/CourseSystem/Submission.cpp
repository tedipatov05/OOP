#include "Submission.h"

#include <iostream>

Submission::Submission(const MyString& user, const MyString& solution, const MyString& courseName, int userId) : user(user), solution(solution), courseName(courseName), userId(userId) {
}

void Submission::print() const {
	std::cout << "User: " << user<< ", " << userId  << ": " << solution << std::endl;
}

void Submission::writeToBinaryFile(std::ofstream& ofs) const {
	this->user.writeToBinaryFile(ofs);
	this->solution.writeToBinaryFile(ofs);
	this->courseName.writeToBinaryFile(ofs);
	ofs.write((const char*)(&userId), sizeof(userId));
}

void Submission::readFromBinaryFile(std::ifstream& ifs) {
	this->user.readFromBinaryFile(ifs);
	this->solution.readFromBinaryFile(ifs);
	this->courseName.readFromBinaryFile(ifs);
	ifs.read((char*)(&userId), sizeof(userId));
}