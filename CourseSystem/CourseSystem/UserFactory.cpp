#include "UserFactory.h"

#include "Admin.h"
#include "Student.h"
#include "Teacher.h"


User* Factory::createUser(UserType t) {
	switch (t) {
	case UserType::Teacher:
		return new Teacher();
	case UserType::Student:
		return new Student();
	case UserType::Admin:
		return new Admin();
	default:
		return nullptr;
	}
}
