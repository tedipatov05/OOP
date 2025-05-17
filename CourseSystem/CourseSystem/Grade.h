#pragma once
#include "Assignment.h"
#include "MyString.h"
#include "Course.h"

class Grade {
public:

	Grade() = default;
	Grade(const Assignment& assignment, const Course& course, const MyString& description, double grade, int userId);


	void printGrade() const;


private:
	Assignment _assignment;
	Course _courseName;
	MyString _description;
	double grade;
	int _userId;

};

