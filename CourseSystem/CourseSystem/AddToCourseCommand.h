#pragma once
#include "Command.h"
#include "Context.h"

class AddToCourseCommand :
    public Command
{
	
public:
	AddToCourseCommand(const MyString& buffer, Context& context);
	void execute() override;
	MyString getCommand() const override;

private:
	/*Context& context;
	MyString buffer;*/

	MyString getCourseNameFromBuffer() const;
	MyString getUserIdFromBuffer() const;
	int findCourseToAdd(const MyString& courseName) const;
	void saveAddedUser(const MyString& filename, const MyString& courseName, int userId) const;

};

