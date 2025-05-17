#pragma once
#include "Course.h"

class CourseRepository
{
public:
	CourseRepository();
	CourseRepository(const CourseRepository& other);
	CourseRepository& operator=(const CourseRepository& other);
	~CourseRepository();

	void addCourse(const Course& course);
	void removeCourse(int index);
	const Course& getCourse(int index) const;
	int getSize() const;

private:
	Course* _courses;
	size_t _size;
	size_t _capacity;

	void copyDynamicMemory(const CourseRepository& other);
	void free();
	void resize();

	//int findIndexToDelete(int index) const;
};

