#include "Soldier.h"
#include "Constants.h"

#include <algorithm>
#include <cstring>
#pragma warning(disable:4996)

namespace Utils{
	

	void copyString(char*& dest, const char* src){
		size_t len = strlen(src);
		dest = new char[len + 1];
		std::strcpy(dest, src);
	}
}

Soldier::Soldier(): _age(INITIAL_AGE), _salary(1000), _fightingSkills(0){
	this->_name = new char[INITIAL_SIZE];
}

Soldier::Soldier(const char* name, size_t age, size_t fightingSkills, double salary) : _age(age), _fightingSkills(fightingSkills), _salary(salary){
	Utils::copyString(this->_name, name);
}

void Soldier::copyDynamic(const Soldier& other){
	Utils::copyString(this->_name, other.name());
}

Soldier::Soldier(const char* name): _age(INITIAL_AGE), _salary(1000), _fightingSkills(0) {
	Utils::copyString(this->_name, name);
}

Soldier::Soldier(const Soldier& soldier) : _age(soldier.age()), _fightingSkills(soldier.fightingSkills()), _salary(soldier.salary()){
	copyDynamic(soldier);
}

Soldier::Soldier(Soldier&& soldier){
	moveDynamic(std::move(soldier));
}

Soldier& Soldier::operator=(const Soldier& soldier){
	if (this != &soldier){
		free();
		copyDynamic(soldier);
		this->_age = soldier.age();
		this->_salary = soldier.salary();
		this->_fightingSkills = soldier.fightingSkills();
	}

	return *this;
	
}

Soldier& Soldier::operator=(Soldier&& soldier) noexcept{
	if (this != &soldier){
		free();
		this->_age = soldier.age();
		this->_salary = soldier.salary();
		this->_fightingSkills = soldier.fightingSkills();
		moveDynamic(std::move(soldier));

	}

	return *this;
}



void Soldier::moveDynamic(Soldier&& other){
	this->_name = other._name;
	other._name = nullptr;
}

void Soldier::free(){
	delete[] this->_name;
}

size_t Soldier::fightingSkills() const{
	return this->_fightingSkills;
}

size_t Soldier::age() const{
	return this->_age;
}

const char* Soldier::name() const{
	return this->_name;
}

double Soldier::salary() const{
	return this->_salary;
}

Soldier::~Soldier(){
	free();
}













