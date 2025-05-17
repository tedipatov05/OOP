


#include <iostream>

#include "Message.h"
#include "MessageTime.h"

int main()
{
	MessageTime* time = new MessageTime();

	//std::cout << time->getTime();

	MyString content = "Test";
	MyString receiver = "user";
	MyString sender = "sender";

	Message* message = new Message(content, receiver, sender);

	std::ofstream ofs("test.dat", std::ios::binary);
	//std::cout << "> mailbox" << std::endl;
	//message->print();
	message->writeToFile(ofs);
	ofs.close();


	std::ifstream ifs("test.dat", std::ios::binary);
	Message** messages = new Message * [2];
	messages[0] = new Message();
	messages[0]->readFromFile(ifs);


	std::cout << "> mailbox" << std::endl;
	messages[0]->print();

	/*std::ofstream ofs("test.dat", std::ios::binary);

	time->writeToBinaryFile(ofs);

	ofs.close();

	MessageTime text;
	std::ifstream ifs("test.dat", std::ios::binary);
	text.readFromBinaryFile(ifs);

	std::cout << text.getTime()<< std::endl;*/




}

