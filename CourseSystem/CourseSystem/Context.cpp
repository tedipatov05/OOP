#include "Context.h"


int Context::current_user_id = 0;

Context::Context(const UserRepository& user_repo) : user_repo(user_repo) {
}

Context::Context(const MyString& filename) {
	this->readFromBinaryFile(filename);
	
}

void Context::readFromBinaryFile(const MyString& filename){
	user_repo.readFromBinaryFile(filename);
}






