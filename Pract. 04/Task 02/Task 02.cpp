// Task 02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#pragma warning(disable:4996)

namespace CONSTANTS {
	constexpr int TASKS_MAX_SIZE = 20;
}


struct Task {
private:
	char* name = nullptr;
	char* condition = nullptr;
	uint32_t points;


	void free() {
		delete[] name;
		name = nullptr;

		delete[] condition;
		condition = nullptr;

		points = 0;
	}




public:

	Task() = default;

	Task(const char* name, const char* condition, uint32_t points) {

		setName(name);
		setCondition(condition);
		setPoints(points);

	}

	~Task() {
		free();
	}

	void setName(const char* name) {
		if (!name || this->name == name) {
			return;
		}

		delete[] this->name;
		size_t size = std::strlen(name) + 1;
		this->name = new char[size];
		std::strcpy(this->name, name);
	}

	void setCondition(const char* condition) {
		if (!condition || this->condition == condition) {
			return;
		}

		delete[] this->condition;
		size_t size = std::strlen(condition) + 1;
		this->condition = new char[size];
		std::strcpy(this->condition, condition);
	}

	void setPoints(uint32_t points) {
		this->points = points;
	}

	uint32_t getPoints() const {
		return this->points;
	}

	char* getName() const {
		return this->name;
	}

	char* getCondition() const {
		return this->condition;
	}

	void writeToFile(std::ofstream& ofs) const {
		size_t nameSize = strlen(this->name);
		ofs.write((const char*)&nameSize, sizeof(nameSize));
		ofs.write((const char*)name, nameSize);

		size_t conditionSize = strlen(this->condition);
		ofs.write((const char*)&conditionSize, sizeof(conditionSize));
		ofs.write((const char*)condition, conditionSize);

		ofs.write((const char*)&points, sizeof(points));

	}


	void readFromFile(std::ifstream& ifs) {

		free();

		size_t nameSize = 0;
		ifs.read((char*)&nameSize, sizeof(size_t));
		name = new char[nameSize + 1] {};
		ifs.read((char*)name, nameSize);
		name[nameSize] = '\0';

		size_t conditionSize = 0;
		ifs.read((char*)&conditionSize, sizeof(size_t));
		condition = new char[conditionSize + 1];
		ifs.read(condition, conditionSize);
		condition[conditionSize] = '\0';

		ifs.read((char*)&points, sizeof(uint32_t));


	}

	/// <summary>
	/// Write task to binary file
	/// </summary>
	/// <param name="filename">name of the file</param>
	void writeToFile(const char* filename) const {

		if (!filename) {
			return;
		}

		std::ofstream ofs(filename, std::ios::binary);

		if (!ofs.is_open()) {
			return;
		}

		writeToFile(ofs);
		ofs.close();

	}

	/// <summary>
	/// Read task from binary file
	/// </summary>
	/// <param name="filename">name of the file </param>
	void readFromFile(const char* filename) {

		if (!filename) {
			return;
		}

		std::ifstream ifs(filename, std::ios::binary);
		if (!ifs.is_open()) {
			return;
		}

		readFromFile(ifs);
		ifs.close();

	}

};

struct Exam {

private:
	Task tasks[CONSTANTS::TASKS_MAX_SIZE];
	size_t tasksSize = 0;
	unsigned lowerBound = 0;

public:

	Exam() = default;

	void addTask(const Task& task) {

		if (tasksSize >= CONSTANTS::TASKS_MAX_SIZE) {
			std::cout << "Could not add a task" << std::endl;

			return;
		}

		tasks[tasksSize].setCondition(task.getCondition());
		tasks[tasksSize].setName(task.getName());
		tasks[tasksSize].setPoints(task.getPoints());

		tasksSize++;

	}

	void changeMin(const unsigned min) {
		this->lowerBound = min;
	}

	uint32_t getMax() const {
		uint32_t max = 0;

		for (size_t i = 0; i < tasksSize; i++) {

			max += tasks[i].getPoints();

		}

		return max;

	}

	void writeToFile(std::ofstream& ofs) const {
		ofs.write((const char*)&tasksSize, sizeof(size_t));

		for (size_t i = 0; i < tasksSize; i++) {
			tasks[i].writeToFile(ofs);
		}

		ofs.write((const char*)&lowerBound, sizeof(lowerBound));


	}

	void writeToFile(const char* filename) const {

		if (!filename) {
			return;
		}

		std::ofstream ofs(filename, std::ios::binary);

		if (!ofs.is_open()) {
			return;
		}

		writeToFile(ofs);

		ofs.close();

	}

	void readFromFile(std::ifstream& ifs) {

		ifs.read((char*)&tasksSize, sizeof(size_t));
		for (size_t i = 0; i < tasksSize; i++) {
			tasks[i].readFromFile(ifs);
		}

		ifs.read((char*)&lowerBound, sizeof(lowerBound));
	}

	void readFromFile(const char* filename) {

		if (!filename) {
			return;
		}

		std::ifstream ifs(filename, std::ios::binary);

		if (!ifs.is_open()) {
			return;
		}

		readFromFile(ifs);
		ifs.close();

	}

};

int main()
{
	Exam exam;
	Task task1("task1", "desc1", 500);
	Task task2("task2", "desc2", 500);

	exam.addTask(task1);
	exam.addTask(task2);
	exam.writeToFile("exam.bin");
	std::cout << exam.getMax() << " ";

	Exam exam2;
	exam2.readFromFile("exam.bin");
	std::cout << exam2.getMax();

	return 0;
}

