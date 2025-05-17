#pragma once
#include "User.h"


enum class UserType {
	Teacher,
	Student,
	Admin
};

class Factory
{
public:
	static User* createUser(UserType t);
};
