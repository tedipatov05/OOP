#include "Context.h"


int Context::next_user_id = 100;

Context::Context(const UserRepository& user_repo) : user_repo(user_repo) {

}

Context::Context(const MyString& filename) {
	this->readFromBinaryFile(filename);
	
}

void Context::readFromBinaryFile(const MyString& filename){
	user_repo.readFromBinaryFile(filename);
}






