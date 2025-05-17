#pragma once
#include <fstream>

#include "Message.h"

class Mailbox {

public:

	Mailbox();
	Mailbox(const Mailbox& mailbox);
	Mailbox& operator=(const Mailbox& other);
	~Mailbox();

	void addMessage(const Message& message);
	void print() const;

	void readFromBinaryFile(std::ifstream& ifs);
	void writeToBinaryFile(std::ofstream& ofs) const;

private:
	Message* messages;
	size_t size;
	size_t capacity;

	void free();
	void copyDynamicMemory(const Mailbox& mailbox);
	void resize();
};



