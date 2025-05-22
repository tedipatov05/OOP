#include "MessageAllCommand.h"

#include <iostream>

MessageAllCommand::MessageAllCommand(const MyString& buffer, Context& system) : buffer(buffer), context(system){

}

MyString MessageAllCommand::getCommand() const {
	return "message_all";
}

void MessageAllCommand::execute() {
	MyString messageContent = getMessageContentFromBuffer();
	if (messageContent == "") {
		std::cout << "No message content provided." << std::endl;
		return;
	}
	User* admin = context.user_repo.getUser(context.user_id);
	if (!admin){
		std::cout << "Admin not found" << std::endl;
	}

	if (context.user_type != UserType::Admin) {
		std::cout << "Only admin can send messages to all students." << std::endl;
		return;
	}
	

	for (size_t i = 0; i < context.user_repo.getSize(); i++){
		if (i == context.user_id){
			continue; // Skip the admin
		}

		User* user = context.user_repo.getUser(i);
		Message msg = Message(messageContent, user->username(), admin->username());
		user->receiveMessage(msg);
	}
}

MyString MessageAllCommand::getMessageContentFromBuffer() const {
	Vector<MyString> tokens = split(buffer, " ");
	if (tokens.size() < 2) {
		return "";
	}
	
	return tokens[1];
}

