#pragma once
#include "Course.h"
#include "UserRepository.h"
#include "Vector.hpp"

class Context
{
public:

	Context() = default;
	Context(const UserRepository& user_repo);
	Context(const MyString& filename);
	/*void addUser(const User& user);
	User* login(int id, const MyString& password);*/

	UserRepository user_repo;
	Vector<Course> courses;
	UserType user_type;
	int user_id;
	static int current_user_id;

	void readFromBinaryFile(const MyString& filename);

};

