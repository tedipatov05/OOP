#include "Message.h"

#include <iostream>

#include "Constants.h"
#include "Utils.h"

Message::Message(){
	this->_content = new MyString();
	this->_receiver = new MyString();
	this->_sender = new MyString();
	this->time = new MessageTime();
}

Message::Message(const MyString& content, const MyString& receiver, const MyString& sender){
	this->_content = new MyString(content);
	this->_receiver = new MyString(receiver);
	this->_sender = new MyString(sender);
	this->time = new MessageTime();
}

Message::Message(const Message& message){
	copyDynamicMemory(message);
}

Message& Message::operator=(const Message& other) {
	if (this != &other) {
		free();
		copyDynamicMemory(other);
	}
	return *this;
}

Message::~Message() {
	free();
	this->_content = nullptr;
	this->_receiver = nullptr;
	this->_sender = nullptr;
	this->time = nullptr;
}

const char* Message::content() const {
	return this->_content->data();
}

void Message::print() const {
	std::cout << "     ";
	std::cout << this->time->getTime() << ", " << "sent by" << *this->_sender << ": " << *this->_content << std::endl;
}

void Message::copyDynamicMemory(const Message& message){
	this->_content = new MyString(*message._content);
	this->_receiver = new MyString(*message._receiver);
	this->_sender = new MyString(*message._sender);
	this->time = new MessageTime(*message.time);
}

void Message::readFromFile(std::ifstream& ifs) {

	//this->_content = new MyString();
	this->_content->readFromBinaryFile(ifs);
	this->_receiver->readFromBinaryFile(ifs);
	this->_sender->readFromBinaryFile(ifs);
	this->time->readFromBinaryFile(ifs);
}

void Message::writeToFile(std::ofstream& ofs) const {
	this->_content->writeToBinaryFile(ofs);
	this->_receiver->writeToBinaryFile(ofs);
	this->_sender->writeToBinaryFile(ofs);
	this->time->writeToBinaryFile(ofs);
}


void Message::free(){
	delete this->_content;
	delete this->_receiver;
	delete this->_sender;
	delete this->time;
}







