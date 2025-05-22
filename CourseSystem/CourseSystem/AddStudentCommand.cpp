#include "AddStudentCommand.h"

#include <iostream>

#include "Student.h"

AddStudentCommand::AddStudentCommand(const MyString& buffer, Context& system) : context(system), buffer(buffer) {
}

MyString AddStudentCommand::getCommand() const {
	return "add_student";
}

void AddStudentCommand::execute(){
	User* user = new Student(getFirstNameFromBuffer(), getLastNameFromBuffer(), getPasswordFromBuffer(), Context::next_user_id);
	Context::next_user_id++;
	context.user_repo.addUser(user);

	std::ofstream file(USERS_FILE.data(), std::ios::binary | std::ios::app);
	if (!file.is_open()) {
		return;
	}

	user->writeToBinaryFile(file);

	std::cout << "Added student " << user->getFirstName() << " " << user->getLastName() << " with ID " << user->getId() << std::endl;
}

MyString AddStudentCommand::getFirstNameFromBuffer() const{
	Vector<MyString> tokens = split(buffer, " ");
	if (tokens.size() < 3) {
		return "";
	}
	return tokens[1];
}

MyString AddStudentCommand::getLastNameFromBuffer() const {
	Vector<MyString> tokens = split(buffer, " ");
	if (tokens.size() < 3) {
		return "";
	}
	return tokens[2];
}

MyString AddStudentCommand::getPasswordFromBuffer() const {
	Vector<MyString> tokens = split(buffer, " ");
	if (tokens.size() < 3) {
		return "";
	}
	return tokens[3];
}


