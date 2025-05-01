#pragma once
#include "Soldier.h"

class Commander: public Soldier
{
public:

	Commander();
	Commander(size_t capacity);
	Commander(const char* name, double salary, size_t fightingSkills, size_t age, const Soldier* soldiers, size_t size);
	Commander(const char* name);
	Commander(const Commander& commander);
	Commander(Commander&& commander) noexcept;
	Commander& operator=(const Commander& other);
	Commander& operator=(Commander&& other) noexcept;

	~Commander();

	double calculateBattalionSalary() const;
	size_t calculateAverageFightingSkill() const;
	size_t calculateSumFightingSkill() const;

	const Soldier* soldiers() const;
	size_t size() const;
	size_t capacity() const;

private:

	Soldier* _soldiers;
	size_t _size;
	size_t _capacity;

	void free();
	void copyDynamic(const Commander& commander);
	void moveDynamic(Commander&& commander);

	void copySoldiers(Soldier*& dest, const Soldier* src, size_t size);
	
};
