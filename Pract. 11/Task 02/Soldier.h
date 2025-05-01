#pragma once

class Soldier{
public:
	Soldier();
	Soldier(const Soldier& soldier);
	Soldier(Soldier&& soldier) noexcept;
	Soldier(const char* name, size_t age, size_t fightingSkills, double salary);
	Soldier(const char* name);

	Soldier& operator=(const Soldier& soldier);
	Soldier& operator=(Soldier&& soldier) noexcept;

	~Soldier();


	const char* name() const;
	double salary() const;
	size_t age() const;
	size_t fightingSkills() const;


private:

	char* _name;
	size_t _age;
	size_t _fightingSkills;
	double _salary;

	void free();
	void copyDynamic(const Soldier& other);
	void moveDynamic(Soldier&& other);


};