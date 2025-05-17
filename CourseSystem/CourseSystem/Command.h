#pragma once
#include "MyString.h"

class Command{
public:

	virtual MyString getCommand() const = 0;
	virtual void execute() = 0;
	virtual ~Command() = default;
};

