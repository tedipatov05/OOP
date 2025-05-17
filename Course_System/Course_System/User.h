#pragma once
#include "Mailbox.h"
#include "Message.h"
#include "MyString.h"
#include "UserFactory.h"

class User {
public:
	User();
	User(const MyString& first_name, const MyString& last_name, const MyString& password, int id);
	User(const User& user);
	User& operator=(const User& other);
	virtual ~User();


	void printMailbox() const;

	const MyString& getFirstName() const;
	const MyString& getLastName() const;
	const MyString& username() const;

	virtual UserType role() const = 0;
	void receiveMessage(const Message& message);
	virtual User* clone() const = 0;

	virtual void writeToBinaryFile(std::ofstream& ofs) const = 0;
	virtual void readFromBinaryFile(std::ifstream& ifs);


protected:
	void free();
	MyString first_name;
	MyString last_name;
	MyString password;
	Mailbox* mailbox;
	int _id;

private:

	
	
	void copyDynamicMemory(const User& user);
};

