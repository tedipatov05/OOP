#pragma once
#include "MessageTime.h"
#include "MyString.h"

class Message {

public:

	Message() = default;
	Message(const MyString& content, const MyString& receiver, const MyString& sender);
	
	const char* content() const;

	void print() const;

	void readFromFile(std::ifstream& ifs);
	void writeToFile(std::ofstream& ofs) const;

private:

	MyString _content;

	MyString _sender; // should be user
	MyString _receiver; // should be user
	MessageTime time;
};
