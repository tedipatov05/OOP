#include "User.h"

#include "UserFactory.h"

User::User() : User("", "", "", 0) {}

User::User(const MyString& first_name, const MyString& last_name, const MyString& password, int id)
	: _id(id), first_name(first_name), last_name(last_name), password(password), mailbox(new Mailbox())
{
	
}

User::User(const User& user) : _id(user._id) {
	this->copyDynamicMemory(user);
}

User& User::operator=(const User& other){
	if (this != &other){
		free();
		copyDynamicMemory(other);
		this->_id = other._id;
	}

	return *this;

}

User::~User() {
	free();
}


void User::copyDynamicMemory(const User& user){
	this->first_name = user.first_name;
	this->last_name = user.last_name;
	this->password = user.password;
	this->mailbox = new Mailbox(*user.mailbox);
}

void User::free(){
	
	delete this->mailbox;
}

void User::printMailbox() const {
	this->mailbox->print();
}

void User::receiveMessage(const Message& message){
	this->mailbox->addMessage(message);
}

void User::readFromBinaryFile(std::ifstream& ifs){

	free();

	this->first_name.readFromBinaryFile(ifs);
	this->last_name.readFromBinaryFile(ifs);
	this->password.readFromBinaryFile(ifs);
	ifs.read((char*)(&this->_id), sizeof(this->_id));
}

const MyString& User::getFirstName() const {
	return this->first_name;
}
const MyString& User::getLastName() const {
	return this->last_name;
}

const MyString& User::username() const {
	return this->first_name + " " + this->last_name;
}




