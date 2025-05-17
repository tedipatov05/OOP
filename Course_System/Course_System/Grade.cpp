#include "Grade.h"

#include <iostream>


Grade::Grade(const Assignment& assignment, const Course& course, const MyString& description, double grade, int userId) :
	_assignment(assignment), _courseName(course), _description(description), grade(grade), _userId(userId) {}

void Grade::printGrade() const {

	std::cout << _courseName.getCourseName() << " | " << _assignment.getTaskName() << " | " << grade << " | " << _description << std::endl;
}



