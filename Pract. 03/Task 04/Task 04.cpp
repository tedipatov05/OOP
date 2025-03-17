// Task 04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <fstream>


void writeNumberArrayToFile(int* arr, size_t size, const char* filename) {

	std::ofstream ofs(filename, std::ios::binary);

	if (!ofs.is_open()) {
		return;
	}

	ofs.write((const char*)arr, size * sizeof(int));
	ofs.close();
}

int* readNumbersFromFile(const char* filename, size_t size) {
	std::ifstream ifs(filename, std::ios::binary);

	if (!ifs.is_open()) {
		return nullptr;
	}

	int* numbers = new int[size];

	ifs.read((char*)numbers, size * sizeof(int));
	ifs.close();

	return numbers;

}

void printArr(const int* arr, size_t size) {
	for (size_t i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
}

int* takeAveryThirdNumber(const int* arr, size_t size, size_t& newSize) {

	newSize = size / 3;
	int* newArr = new int[newSize];
	size_t idx = 0;
	for (size_t i = 2; i < size; i += 2) {
		newArr[idx] = arr[i];
		idx++;
	}

	return newArr;

}


int main()
{
	int n;
	std::cin >> n;
	int* buffer = new int[n];

	for (size_t i = 0; i < n; i++) {
		std::cin >> buffer[i];
	}

	writeNumberArrayToFile(buffer, n, "input.dat");

	delete[] buffer;

	int* numbers = readNumbersFromFile("input.dat", n);
	size_t newSize = 0;

	//printArr(numbers, n);

	int* everyThirdNum = takeAveryThirdNumber(numbers, n, newSize);
	delete[] numbers;

	printArr(everyThirdNum, newSize);

	delete[] everyThirdNum;


}

