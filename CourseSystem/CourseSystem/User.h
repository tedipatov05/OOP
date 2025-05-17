#pragma once
#pragma once

#include "Message.h"
#include "MyString.h"
#include "UserFactory.h"
#include "Mailbox.h"

class User {
public:
	User();
	User(const MyString& first_name, const MyString& last_name, const MyString& password, int id);
	virtual ~User() = default;


	void printMailbox() const;

	const MyString& getFirstName() const;
	const MyString& getLastName() const;
	MyString username() const;
	int getId() const;
	const MyString& getPassword() const;

	virtual UserType role() const = 0;
	void receiveMessage(const Message& message);
	virtual User* clone() const = 0;

	virtual void writeToBinaryFile(std::ofstream& ofs) const = 0;
	virtual void readFromBinaryFile(std::ifstream& ifs);


protected:
	MyString first_name;
	MyString last_name;
	MyString password;
	Mailbox mailbox;
	int _id;

};

