#include "LogoutCommand.h"

#include <iostream>

LogoutCommand::LogoutCommand(const MyString& buffer, Context& system) : context(system), buffer(buffer) {
}

MyString LogoutCommand::getCommand() const {
	return "logout";
}

void LogoutCommand::execute(){
	if (this->context.user_id != -1){
		this->context.user_id = -1;
		this->context.user_type = UserType::None;
		
	} else{
		std::cout << "You are not logged in." << std::endl;
	}
}


