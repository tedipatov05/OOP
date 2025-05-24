#pragma once
#include "Assignment.h"
#include "MyString.h"
#include "UserRepository.h"
#include "Vector.hpp"

class Course {

public:

	Course() = default;
	Course(const MyString& courseName, const MyString& password);

	void addParticipant(const User* user); // add a participant to the course
	void addAssignment(const Assignment& assignment); // add an assignment to the course

	const MyString getCourseName() const;
	const Vector<Assignment>& getAssignments() const;

	void writeToBinaryFile(std::ofstream& ofs) const;
	void readFromBinaryFile(std::ifstream& ifs);

	bool isUserInCourse(int userId) const;
	bool isPasswordCorrect(const MyString& password) const;



private:

	Vector<int> users;
	MyString _courseName;
	MyString _password;
	Vector<Assignment> _assignments;


};

