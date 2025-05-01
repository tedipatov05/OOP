#pragma once
#include "Commander.h"
#include "Soldier.h"

class General : public Soldier
{
public:

	General();
	General(const char* name, double salary, size_t fightingSkills, size_t age, const Commander* commanders, size_t size, const char* description);
	General(const char* name);
	General(size_t capacity);
	General(const General& general);
	General(General&& general) noexcept;
	General& operator=(const General& general);
	General& operator=(General&& general) noexcept;
	~General();

	double calculateArmySalary() const;
	size_t calculateArmyAverageFightingSkill() const;
	size_t calculateArmySumFightingSkill() const;


	size_t capacity() const;
	size_t size() const;
	const Commander* commanders() const;
	const char* description() const;

private:
	Commander* _commanders;
	size_t _size;
	size_t _capacity;
	char* _description;

	void free();
	void copyDynamic(const General& general);
	void moveDynamic(General&& general);

	void copyCommanders(Commander*& dest, const Commander* src, size_t size);
	
};
