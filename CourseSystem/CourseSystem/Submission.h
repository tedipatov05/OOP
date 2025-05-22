#pragma once
#include "MyString.h"


class Submission
{
public:
	Submission() = default;
	Submission(const MyString& user, const MyString& solution, const MyString& courseName, int userId);

	void print() const;

	void writeToBinaryFile(std::ofstream& ofs) const;
	void readFromBinaryFile(std::ifstream& ifs);

private:
	MyString user;
	MyString solution;
	MyString courseName;
	int userId;

};


