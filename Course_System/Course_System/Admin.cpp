#include "Admin.h"

UserType Admin::role() const
{
	return UserType::Admin;
}

User* Admin::clone() const
{
	return new Admin(*this);
}

void Admin::writeToBinaryFile(std::ofstream& ofs) const
{
}
