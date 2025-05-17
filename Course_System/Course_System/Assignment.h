#pragma once
#include "Course.h"
#include "MyString.h"
#include "Submission.h"
#include "User.h"

class Assignment{

public:

	Assignment() = default;
	Assignment(const Course& course, const MyString& taskName, const MyString& description);
	
	void print() const;

	const MyString& getTaskName() const;

private:
	Course _course; // should be class course
	MyString _taskName;
	MyString _description; // may be not here
	Submission* submissions;

};

