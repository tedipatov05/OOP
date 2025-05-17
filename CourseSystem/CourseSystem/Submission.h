#pragma once
#include "MyString.h"


class Submission
{
public:
	Submission() = default;
	Submission(const MyString& user, const MyString& solution, int courseId, int userId);

	void print() const;

private:
	MyString user;
	MyString solution;
	int courseId;
	int userId;

};


