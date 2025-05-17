// Task 01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Classroom.h"
#include "Student.h"

int main()
{
    Student** students = new Student * [3];
    students[0] = new Student("Test1", 1);
    students[1] = new Student("Test2", 2);
    students[2] = new Student("Test3", 3);

    Classroom room((const Student**)students, 3);

    /*room.swapStudents(1, 2);

    std::cout << room._students[1]->name() << std::endl;*/

    room.suspendStudent(0);
    std::cout << room._students[0]->name() << std::endl;
    std::cout << room._students[1]->name() << std::endl;
    std::cout << room.capacity() << std::endl;

    room.addStudent(Student("Test4", 4));
    room.addStudent(Student("Test5", 5));
    room.addStudent(Student("Test6", 6));

    std::cout << room.capacity();

}
