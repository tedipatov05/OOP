#pragma once
#include "MyString.h"
#include "User.h"

class Admin : public User
{

public:

	UserType role() const override;
	User* clone() const override;
	void writeToBinaryFile(std::ofstream& ofs) const override;
};

