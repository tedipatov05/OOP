#pragma once
#include "Course.h"
#include "UserRepository.h"
#include "Vector.hpp"
#include "Constants.h"

class Context
{
public:

	Context();
	Context(const UserRepository& user_repo, const Vector<Course>& courses);
	Context(const MyString& usersFilename, const MyString& coursesFilename, const MyString& messagesFile , const MyString& usersCoursesFile, 
		const MyString& assignmentsFile, const MyString& submissionsFile, const MyString& gradesFile);


	UserRepository user_repo;
	Vector<Course> courses;
	UserType user_type;
	int user_id;
	static int next_user_id;


	void readFromBinaryFile(const MyString& usersFilename, const MyString& coursesFilename, const MyString& messagesFile, const MyString& usersCoursesFile, 
		const MyString& assignmentsFile, const MyString& submissionsFile, const MyString& gradesFile);

	User* findUserByUsername(const MyString& username) const;
	Course* findCourseByName(const MyString& courseName) const;
	Assignment* findAssignmentByName(const MyString& course, const MyString& assignmentName) const;
	Submission* findSubmissionByName(const MyString& course, const MyString& assignmentName, int userId) const;


	void readMessages(const MyString& filename);
	void readCourses(const MyString& filename);
	void readUserCourses(const MyString& filename);
	void readAssignments(const MyString& filename);
	void readSubmissions(const MyString& filename);
	void readGrades(const MyString& filename);
};

