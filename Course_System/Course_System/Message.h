#pragma once
#include "MessageTime.h"
#include "MyString.h"
#include <iostream>
#include <fstream>

class Message {

public:

	Message();
	Message(const MyString& content, const MyString& receiver, const MyString& sender);
	Message(const Message& message);
	Message& operator=(const Message& other);
	~Message();

	const char* content() const;

	void print() const;

	void readFromFile(std::ifstream& ifs);
	void writeToFile(std::ofstream& ofs) const;

private:

	MyString* _content;

	MyString* _sender; // should be user
	MyString* _receiver; // should be user
	MessageTime* time;

	void free();
	void copyDynamicMemory(const Message& message);


};

