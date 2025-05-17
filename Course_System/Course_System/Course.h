#pragma once
#include "User.h"
#include "UserRepository.h"

class Course{

public:

	Course();
	Course(const MyString& courseName, const MyString& courseDescription, const MyString& password);
	
	void addParticipant(const User* user); // add a participant to the course

	const MyString getCourseName() const;

private:

	UserRepository _userRepository;
	MyString _courseName;
	MyString _courseDescription;
	MyString _password;


};

