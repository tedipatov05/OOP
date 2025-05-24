#include "MailboxCommand.h"

#include <iostream>

MailboxCommand::MailboxCommand(const MyString& buffer, Context& system) : Command(buffer, system) {
}

MyString MailboxCommand::getCommand() const {
	return "mailbox";
}

void MailboxCommand::execute(){
	if (context.user_id == -1){
		std::cout << "You are not logged in!" << std::endl;
		return;
	}

	User* user = context.user_repo.getUser(context.user_id);
	if (user == nullptr) {
		std::cout << "User not found!" << std::endl;
		return;
	}

	user->printMailbox();
}
