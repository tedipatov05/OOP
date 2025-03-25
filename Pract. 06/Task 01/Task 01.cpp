// Task 01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#pragma warning(disable:4996)

class Message{

	char* sender;
	char* receiver;
	char* message;
	int fontSize;


	void copyStrings(char*& destination, const char* source){
		size_t len = strlen(source);
		destination = new char[len + 1];
		strcpy(destination, source);

	}

	void copyFrom(const Message& message){

		copyStrings(this->sender, message.sender);
		copyStrings(this->receiver, message.receiver);
		copyStrings(this->message, message.message);
		setFontSize(message.fontSize);
	}

	void free(){
		delete[] sender;
		delete[] receiver;
		delete[] message;
	}

public:
	Message() = default;

	Message(const Message& other) {
		copyFrom(other);
	}

	Message& operator=(const Message& other){
		if (this != &other){
			free();
			copyFrom(other);
		}

		return *this;

	}

	void setFontSize(int fontSize){
		this->fontSize = fontSize;
	}


	~Message(){
		free();
	}
	

};

int main()
{
    std::cout << "Hello World!\n";
}

