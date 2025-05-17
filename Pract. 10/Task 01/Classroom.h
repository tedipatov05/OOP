#pragma once
#include "Student.h"



class Classroom{


public:
	Classroom();
	Classroom(const Student** students, int count);
    Classroom(const Classroom& classroom);
    Classroom(Classroom&& classroom) noexcept;

    Classroom& operator=(const Classroom& classroom);
    Classroom& operator=(Classroom&& classroom) noexcept;

    void suspendStudent(int index);
    int freeSpaces() const;
    int getEmptiestRow(int count) const;
    void swapStudents(int index1, int index2);

    void addStudent(const Student& student);
    void addStudent(Student&& student);

    int size() const;
    int capacity() const;

    ~Classroom();
    Student** _students;

private:

	
	int _size;
	int _capacity;

    void resize(int capacity);
    void copyDynamic(const Classroom& room);
    void moveDynamic(Classroom&& room);
    void free();



};

