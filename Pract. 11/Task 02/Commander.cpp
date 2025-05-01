#include "Constants.h"
#include "Commander.h"
#include <utility>
#include "Utils.h"

Commander::Commander() {
	this->_soldiers = new Soldier[INITIAL_CAPACITY];
	this->_size = 0;
	this->_capacity = INITIAL_CAPACITY;
}

Commander::Commander(const char* name, double salary, size_t fightingSkills, size_t age, const Soldier* soldiers, size_t size) : Soldier(name, age, fightingSkills, salary), _size(size), _capacity(dataToAlloc(size)) {
	this->_soldiers = new Soldier[_capacity];
	copySoldiers(this->_soldiers, soldiers, size);
}

Commander::Commander(size_t capacity) :Soldier(), _size(0), _capacity(capacity) {
	this->_soldiers = new Soldier[capacity];
}

Commander::Commander(const char* name) : Soldier(name), _size(), _capacity(INITIAL_CAPACITY){
	this->_soldiers = new Soldier[this->capacity()];
}

Commander::Commander(const Commander& commander) : Soldier(commander), _size(commander.size()), _capacity(commander.capacity()) {
	copyDynamic(commander);
}

Commander::Commander(Commander&& commander) noexcept : _size(commander.size()), _capacity(commander.capacity()) {
	moveDynamic(std::move(commander));
}

Commander& Commander::operator=(const Commander& other) {
	if (this != &other) {
		Soldier::operator=(other);
		free();
		copyDynamic(other);
		this->_size = other.size();
		this->_capacity = other.capacity();
	}

	return *this;
}

Commander& Commander::operator=(Commander&& other) noexcept {
	if (this != &other) {
		Soldier::operator=(std::move(other));
		free();
		this->_size = other.size();
		this->_capacity = other.capacity();
		moveDynamic(std::move(other));
	}

	return *this;
}

Commander::~Commander() {
	free();
}

const Soldier* Commander::soldiers() const {
	return this->_soldiers;
}

size_t Commander::capacity() const {
	return this->_capacity;
}

size_t Commander::size() const {
	return this->_size;
}

double Commander::calculateBattalionSalary() const {
	if (this->size() == 0) {
		return 0;
	}

	double sum = this->salary();
	for (size_t i = 0; i < this->size(); i++) {
		sum += this->soldiers()[i].salary();
	}

	return sum;
}

size_t Commander::calculateSumFightingSkill() const {
	if (this->size() == 0) {
		return 0;
	}

	size_t sum = this->fightingSkills();
	for (size_t i = 0; i < this->size(); i++) {
		sum += this->soldiers()[i].fightingSkills();
	}

	return sum;
}

size_t Commander::calculateAverageFightingSkill() const {
	return calculateSumFightingSkill() / this->size();
}


void Commander::copyDynamic(const Commander& commander) {
	this->_soldiers = new Soldier[commander.capacity()];
	copySoldiers(this->_soldiers, commander.soldiers(), commander.size());
}

void Commander::moveDynamic(Commander&& commander) {
	this->_soldiers = commander._soldiers;
	commander._soldiers = nullptr;
}

void Commander::copySoldiers(Soldier*& dest, const Soldier* src, size_t size) {
	for (size_t i = 0; i < size; i++) {
		dest[i] = src[i];
	}
}


void Commander::free() {
	delete[] this->_soldiers;
}




