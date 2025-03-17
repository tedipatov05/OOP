// Task 01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

constexpr int BLOCK_SIZE = 32;

int getMessageLength(std::ifstream& ifs) {

	int ifsInitialPosition = ifs.tellg();

	ifs.seekg(0);


	int16_t nextBlockIndex = 0;

	uint16_t currentLengthMessage = 0;

	int totalMessage = 0;

	while (true){
		ifs.seekg(nextBlockIndex * BLOCK_SIZE);

		ifs.read((char*)&nextBlockIndex, sizeof(nextBlockIndex));
		ifs.read((char*)&currentLengthMessage, sizeof(currentLengthMessage));

		totalMessage += currentLengthMessage;

		if (nextBlockIndex == -1){
			break;
		}

	}



	ifs.seekg(ifsInitialPosition);

	return totalMessage;

}

char* readMessage(std::ifstream& ifs, int totalMessageLength){

	char* message = new char[totalMessageLength + 1];
	char* messageInterator = message;

	int16_t nextBlockIndex = 0;

	uint16_t currentLengthMessage = 0;
	size_t currentIndex;

	while (true) {
		ifs.seekg(nextBlockIndex * BLOCK_SIZE);

		ifs.read((char*)&nextBlockIndex, sizeof(nextBlockIndex));
		ifs.read((char*)&currentLengthMessage, sizeof(currentLengthMessage));

		ifs.read(messageInterator, currentLengthMessage);
		messageInterator += currentLengthMessage;
		


		if (nextBlockIndex == -1) {
			break;
		}

	}

	message[totalMessageLength] = '\0';

	
}

int main()
{
	std::ifstream ifs("blocks.dat", std::ios::binary);

	if (!ifs.is_open())
	{
		return -1;
	}

	int messageLength = getMessageLength(ifs);

	

}

