#include "Submission.h"

#include <iostream>

Submission::Submission(const MyString& user, const MyString& solution, int courseId, int userId) : user(user), solution(solution), courseId(courseId), userId(userId) {
}

void Submission::print() const {
	std::cout << "User: " << user<< ", " << userId  << ": " << solution << std::endl;
}
