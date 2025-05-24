#pragma once
#include "Command.h"
#include "Context.h"

class AssignHomeworkCommand : public Command {
public:
	AssignHomeworkCommand(const MyString& buffer, Context& ctx);
	void execute() override;
	MyString getCommand() const override;

private:
	//Context& context;
	//MyString buffer;

	MyString getCourseName() const;
	MyString getHomeworkName() const;
	void saveAssignment(const MyString& filename, const Assignment& assignment) const;
};

