#include "UserFactory.h"
#include "Student.h"
#include "Teacher.h"
#include "Admin.h"

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
