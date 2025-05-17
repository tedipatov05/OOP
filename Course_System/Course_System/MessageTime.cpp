#include "MessageTime.h"

#include <cstring>
#include <ctime>
#pragma warning(disable:4996)

MessageTime::MessageTime(){
	setCurrentTime();
}

MessageTime::MessageTime(const MessageTime& message_time){
    copyDynamicMemory(message_time);
}

MessageTime& MessageTime::operator=(const MessageTime& message_time){
	if (this != &message_time){
        free();
        copyDynamicMemory(message_time);
	}

    return *this;
}

MessageTime::~MessageTime(){
    free();
}

void MessageTime::free(){
	delete[] this->_time;
}

void MessageTime::setCurrentTime(){

    time_t now = time(nullptr);
    tm* ltm = localtime(&now);

    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "%H:%M %Y-%m-%d", ltm);

    this->_time = new char[strlen(buffer) + 1];
    std::strcpy(_time, buffer);

    this->len = strlen(buffer) + 1;
}

const char* MessageTime::getTime() const{
    return this->_time;
}

void MessageTime::copyDynamicMemory(const MessageTime& message_time){
    size_t len = strlen(message_time.getTime());
    this->_time = new char[len + 1];
    strcpy(this->_time, message_time.getTime());
}

void MessageTime::readFromBinaryFile(std::ifstream& ifs) {
    free();
    size_t size;
	ifs.read((char*)&size, sizeof(size));
	this->_time = new char[size + 1];
	ifs.read(this->_time, size);
}

void MessageTime::writeToBinaryFile(std::ofstream& ofs) const {
	//size_t size = strlen(this->_time);
	ofs.write((const char*)&len, sizeof(len));
	ofs.write(this->_time, len);
}



