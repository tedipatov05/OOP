#pragma once
#include "Course.h"
#include "CourseRepository.h"
#include "User.h"
class Student : public User{

public:
	Student();
	Student(const MyString& first_name, const MyString& last_name, const MyString& password, int id);

	UserType role() const override;
	User* clone() const override;

	void writeToBinaryFile(std::ofstream& ofs) const override;

private:

	CourseRepository _courses;

};

