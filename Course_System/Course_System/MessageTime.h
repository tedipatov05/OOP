#pragma once
#include <fstream>

class MessageTime{

public:

	MessageTime();
	MessageTime(const MessageTime& message_time);
	MessageTime& operator=(const MessageTime& message_time);
	~MessageTime();

	const char* getTime() const;

	void readFromBinaryFile(std::ifstream& ifs);
	void writeToBinaryFile(std::ofstream& ofs) const;

private:

	char* _time;
	size_t len;

	void setCurrentTime();
	void free();
	void copyDynamicMemory(const MessageTime& message_time);

};

