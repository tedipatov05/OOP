#include "Message.h"
#include <iostream>

Message::Message(const MyString& content, const MyString& receiver, const MyString& sender) {
	this->_content = content;
	this->_receiver = receiver;
	this->_sender = sender;
}



const char* Message::content() const {
	return this->_content.data();
}

void Message::print() const {
	std::cout << "     ";
	std::cout << this->time.getTime() << ", " << "sent by " << this->_sender << ": " << this->_content << std::endl;
}

void Message::readFromFile(std::ifstream& ifs) {

	//this->_content = new MyString();
	this->_content.readFromBinaryFile(ifs);
	this->_receiver.readFromBinaryFile(ifs);
	this->_sender.readFromBinaryFile(ifs);
	this->time.readFromBinaryFile(ifs);
}

void Message::writeToFile(std::ofstream& ofs) const {
	this->_content.writeToBinaryFile(ofs);
	this->_receiver.writeToBinaryFile(ofs);
	this->_sender.writeToBinaryFile(ofs);
	this->time.writeToBinaryFile(ofs);
}


