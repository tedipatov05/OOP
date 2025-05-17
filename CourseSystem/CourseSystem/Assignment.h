#pragma once
#include "MyString.h"
#include "Submission.h"
#include "Vector.hpp"

class Assignment {

public:

	Assignment() = default;
	Assignment(const MyString& taskName, const MyString& description);

	void print() const;

	const MyString& getTaskName() const;
	void addSubmission(const Submission& submission);

private:
	MyString _taskName;
	MyString _description; 
	Vector<Submission> _submissions;
};


