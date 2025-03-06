// Task 03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//using namespace std;

constexpr int MAX_STUDENTS = 256;
constexpr int MAX_NAME = 256;

enum TypeStudent {
	Freshman,
	Sophomore,
	Junior,
	Senior
};


struct Student{
    char name[30];
    char surname[30];
    char egn[11];
	int age;
	TypeStudent type;
};


struct University{
	char name[MAX_NAME];
	Student students[MAX_STUDENTS];
	int count;
};

bool hasStudent(const University& university, const Student& student){

	size_t index = 0;
	while (university.count != index) {
		if (!strcmp(university.students[index].egn, student.egn)) {
			return true;
		}
		index++;
	}

	return false;
}

void addStudent(University& university, const Student& student) {
	if (hasStudent(university, student)) {
		std::cout << "Student already exists" << std::endl;
		return;
	}

	for (size_t i = 0; i < MAX_STUDENTS; i++) {
		if (university.students[i].egn[0] == '\0') {
			university.students[i] = student;
			university.count++;
			return;
		}
	}

	std::cout << "No more space for students" << std::endl;
}

int findIndexOfStudent(const University& university, char egn[11]) {
	
	for (size_t i = 0; i < university.count; i++) {
		if (!strcmp(university.students[i].egn, egn)) {
			return i;
		}
	}

	return -1;
}

void removeStudent(University& university, char egn[11]){
	int indexOfStudent = findIndexOfStudent(university, egn);

	if (indexOfStudent == -1){
		std::cout << "Student not found" << std::endl;
	}

	for (size_t i = indexOfStudent + 1; i < university.count; i++){
		university.students[i - 1] = university.students[i];
	}

	std::cout << "Student removed" << std::endl;
}

TypeStudent findTypeStudent(int age) {
	if (age < 18) {
		return Freshman;
	}
	else if (age < 21) {
		return Sophomore;
	}
	else if (age < 24) {
		return Junior;
	}
	else {
		return Senior;
	}
}

void printStudents(TypeStudent type, const University& university) {
	for (size_t i = 0; i < university.count; i++) {
		if (university.students[i].type == type) {
			std::cout << university.students[i].name << " " << university.students[i].surname << std::endl;
		}
	}
}



int main()
{
	char name[30];
	char surname[30];
	char egn[11];

	std::cin >> name;
	std::cin >> surname;
	std::cin >> egn;
	Student student;
	strcpy(student.name, name);
	strcpy(student.surname, surname);
	strcpy(student.egn, egn);
	std::cin >> student.age;
	student.type = findTypeStudent(student.age);



    
}

