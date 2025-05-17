#pragma once
#include "Assignment.h"
#include "MyString.h"
#include "UserRepository.h"
#include "Vector.hpp"

class Course {

public:

	Course() = default;
	Course(const MyString& courseName, const MyString& courseDescription, const MyString& password);

	void addParticipant(const User* user); // add a participant to the course
	void addAssignment(const Assignment& assignment); // add an assignment to the course

	const MyString getCourseName() const;


private:

	UserRepository _userRepository;
	MyString _courseName;
	MyString _courseDescription;
	MyString _password;
	Vector<Assignment> _assignments;


};

