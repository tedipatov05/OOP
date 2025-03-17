

#include <iostream>
#include <fstream>
#pragma warning(disable:4996)


struct Set {

private:

	uint32_t* numbers = nullptr;
	size_t size = 0;
	size_t currentCount = 0;



	void free() {
		delete[] numbers;
		size = 0;
		currentCount = 0;
	}

	size_t getNextPowerOfTwo(size_t size) {
		size <<= 1;

		return size;
	}

	void resize(size_t newSize) {
		this->size = newSize;
		uint32_t* newNumbers = new uint32_t[newSize];
		size_t toCopy = (size < newSize) ? size : newSize;

		for (size_t i = 0; i < toCopy; i++) {
			newNumbers[i] = numbers[i];
		}

		delete[] numbers;
		numbers = newNumbers;
		newNumbers = nullptr;

	}

	void deserialize(std::ifstream& ifs) {

		free();

		ifs.read((char*)&size, sizeof(size));
		ifs.read((char*)numbers, size * sizeof(uint32_t));
		ifs.read((char*)&currentCount, sizeof(currentCount));

	}

	void deserialize(const char* filename) {
		if (!filename) {
			return;
		}

		std::ifstream ifs(filename, std::ios::binary);

		if (!ifs.is_open()) {
			return;
		}

		deserialize(ifs);
		ifs.close();
	}


public:

	Set() {
		size = 8;
		numbers = new uint32_t[size];
		currentCount = 0;
	}

	Set(const char* filename) {
		deserialize(filename);
	}

	~Set() {
		free();
	}

	size_t getSize() const {
		return this->size;
	}

	uint32_t* getNumbers() const {
		return this->numbers;
	}

	size_t getCount() const {
		return this->currentCount;
	}




	int contains(uint32_t elementToBeFound) const {

		if (currentCount == 0 || elementToBeFound < 0) {
			return -1;
		}

		for (size_t i = 0; i < currentCount; i++) {
			if (numbers[i] == elementToBeFound) {
				return i;
			}
		}

		return -1;
	}

	bool addElement(int element) {

		if (this->contains(element)) {
			return false;
		}

		if (currentCount + 1 >= size) {
			size_t newSize = getNextPowerOfTwo(this->size);
			resize(newSize);
		}

		numbers[currentCount++] = element;
		return true;
	}

	bool deleteElement(int element) {
		int elementIndex = this->contains(element);

		if (elementIndex == -1) {
			return false;
		}

		for (size_t i = elementIndex; i < currentCount; i++) {
			numbers[i] = numbers[i + 1];
		}

		this->currentCount--;

		if (currentCount / size < 0.3) {
			size_t newSize = size == 8 ? size : size / 2;
			resize(newSize);
		}
	}

	void print() const {
		for (size_t i = 0; i < currentCount; i++) {
			std::cout << numbers[i] << " ";
		}
		std::cout << std::endl;
	}

	void serialize(std::ofstream& ofs) const {

		ofs.write((const char*)&size, sizeof(size));
		ofs.write((const char*)numbers, size * sizeof(uint32_t));
		ofs.write((const char*)&currentCount, sizeof(currentCount));

	}

	void serialize(const char* filename) const {

		if (!filename) {
			return;
		}

		std::ofstream ofs(filename, std::ios::binary);

		if (!ofs.is_open()) {
			return;
		}

		serialize(ofs);
		ofs.close();

	}

	void setUnion(const Set& other) {
		size_t otherCount = other.getCount();
		uint32_t* otherNumbers = other.getNumbers();

		for (size_t i = 0; i < otherCount; i++) {

			if (!this->contains(otherNumbers[i])) {
				this->addElement(otherNumbers[i]);
			}
		}

	}

	void setIntersection(const Set& other) {
		size_t otherCount = other.getCount();
		uint32_t* otherNumbers = other.getNumbers();

		for (size_t i = 0; i < currentCount; i++) {
			if (!other.contains(this->numbers[i])) {
				this->deleteElement(this->numbers[i]);
			}
		}

	}



};

int main() {

	std::cout << "Hello World!\n";
}

