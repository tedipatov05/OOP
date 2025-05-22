// CourseSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include "AddTeacherCommand.h"
#include "Admin.h"
#include "LoginCommand.h"
#include "Message.h"
#include "Student.h"
#include "Teacher.h"
#include "User.h"
#include "UserRepository.h"
#include "Utils.h"

int main()
{
	//MessageTime* time = new MessageTime();

	////std::cout << time->getTime();

	//MyString content = "Test";
	//MyString receiver = "user";
	//MyString sender = "sender";

	//Message* message = new Message(content, receiver, sender);

	//std::ofstream ofs("test.dat", std::ios::binary);
	////std::cout << "> mailbox" << std::endl;
	////message->print();
	//message->writeToFile(ofs);
	//ofs.close();


	//std::ifstream ifs("test.dat", std::ios::binary);
	//Message** messages = new Message * [2];
	//messages[0] = new Message();
	//messages[0]->readFromFile(ifs);


	//std::cout << "> mailbox" << std::endl;
	//messages[0]->print();


	//UserRepository userRepo;

	User* admin = new Admin("Alice", "Johnson", "adminpass", 0);
	User* teacher1 = new Teacher("John", "Doe", "password123", 1);
	User* student = new Student("Jane", "Smith", "password456", 2);

	//userRepo.addUser(admin);
	//userRepo.addUser(teacher1);
	//userRepo.addUser(student);

	////std::ofstream ofs("users.dat", std::ios::binary);

	//userRepo.writeToBinaryFile("users.dat");

	//UserRepository repo2;
	//repo2.readFromBinaryFile("users.dat");

	//std::cout << "Users in repo2:" << std::endl;
	//User* user3 = repo2.findUser("John");
	//std::cout << "Found user: " << user3->username() << std::endl;

	/*Context context = Context("users.dat");

	while (true){
		std::cout << "> ";
		char buffer[1024];

		std::cin.getline(buffer, 1024);

		MyString command(buffer);

		AddTeacherCommand addTeacherCommand(command, context);

		addTeacherCommand.execute();



		if (command.isEmpty()){
			break;
		}
	}*/


	Course* course = new Course("Course1", "password123");
	course->addParticipant(student);
	Assignment* assignment = new Assignment("Assignment1", "Description1");
	Submission* submission = new Submission("Jane Smith", "Solution1", course->getCourseName(), student->getId());
	assignment->addSubmission(*submission);
	course->addAssignment(*assignment);

	std::ofstream ofs("course.dat", std::ios::binary);
	if (!ofs.is_open()) {
		return 1;
	}

	course->writeToBinaryFile(ofs);
	ofs.close();

	std::ifstream ifs("course.dat", std::ios::binary);

	Course course1;
	course1.readFromBinaryFile(ifs);





}

