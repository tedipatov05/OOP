// Task 03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>

namespace Constants
{
	constexpr int BUFFER_SIZE = 1024;
	const char DELIM = ' ';
}

unsigned getCharOccurrences(std::stringstream& ss, const char ch){

	unsigned occurs = 0;

	while (true){

		int currCh = ss.get();

		if (ss.eof()){

			ss.clear();
			ss.seekg(0, std::ios::beg);
			return occurs;
		}

		if (currCh == ch){
			occurs++;
		}
	}

}

int* getArrayFromStr(char* str, size_t& size){

	std::stringstream ss(str);

	size = getCharOccurrences(ss, Constants::DELIM) + 1;

	int* arr = new int[size];

	for (size_t i = 0;i < size; i++){
		int num;
		ss >> num;
		arr[i] = num;
	}

	return arr;
}

int findSumOfArray(const int* arr, size_t size){
	int sum = 0; 
	for (size_t i = 0; i < size; i++) {
		sum += arr[i];
	}

	return sum;

}

void findBiggestAndSmallestNum(const int* arr, size_t size, int& min, int& max) {
	min = arr[0];
	max = arr[0];

	for (int i = 0; i < size; i++) {
		if (arr[i] < min) {
			min = arr[i];
		} else if (arr[i] > max) {
			max = arr[i];
		}
	}

}

void printArr(const int* arr, size_t size) {
	for (size_t i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
}


int main()
{
	char buffer[Constants::BUFFER_SIZE];

	size_t size = 0;

	std::cin.getline(buffer, Constants::BUFFER_SIZE);
	int* arr = getArrayFromStr(buffer, size);
	int sum = findSumOfArray(arr, size);
	int min, max;
	findBiggestAndSmallestNum(arr, size, min, max);
	std::cout << sum << ' ' << min << ' ' << max << std::endl;


}

