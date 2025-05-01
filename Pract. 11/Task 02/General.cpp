#include "General.h"

#include <algorithm>

#include "Constants.h"
#include "Utils.h"


General::General() : _size(0), _capacity(INITIAL_CAPACITY) {
	this->_commanders = new Commander[this->_capacity];
	this->_description = new char[INITIAL_CAPACITY] {'\0'};
}

General::General(const char* name) : Soldier(name), _size(0), _capacity(INITIAL_CAPACITY) {
	this->_commanders = new Commander[this->_capacity];
	this->_description = new char[INITIAL_CAPACITY] {'\0'};
}

General::General(const char* name, double salary, size_t fightingSkills, size_t age, const Commander* commanders, size_t size, const char* description)
	: Soldier(name, age, fightingSkills, salary), _size(size), _capacity(dataToAlloc(size)) {
	this->_commanders = new Commander[this->capacity()];
	copyCommanders(this->_commanders, commanders, size);
	setString(this->_description, description);
}

General::General(size_t capacity) : Soldier(), _size(0), _capacity(capacity) {
	this->_commanders = new Commander[this->_capacity];
	this->_description = new char[INITIAL_CAPACITY] {'\0'};
}

General::General(const General& general)
: Soldier(general), _size(general.size()), _capacity(general.capacity()) {

	copyDynamic(general);
}

General::General(General&& general) noexcept : Soldier(std::move(general)), _size(general.size()), _capacity(general.capacity()){
	moveDynamic(std::move(general));
}

General& General::operator=(const General& general){
	if (this != &general){
		Soldier::operator=(general);
		free();
		copyDynamic(general);
		this->_size = general.size();
		this->_capacity = general.capacity();
	}

	return *this;
}

General& General::operator=(General&& general) noexcept{
	if (this != &general){
		Soldier::operator=(std::move(general));
		free();
		moveDynamic(std::move(general));
		this->_size = general.size();
		this->_capacity = general.capacity();
	}

	return *this;
}

General::~General(){
	free();
}

size_t General::capacity() const{
	return this->_capacity;
}

size_t General::size() const{
	return this->_size;
}

const char* General::description() const{
	return this->_description;
}
const Commander* General::commanders() const {
	return this->_commanders;
}

double General::calculateArmySalary() const{
	double sum = this->salary();
	for (size_t i = 0; i < this->size(); i++){
		sum += this->commanders()[i].calculateBattalionSalary();
	}

	return sum;
}

size_t General::calculateArmySumFightingSkill() const{
	size_t sum = this->fightingSkills();
	for (size_t i = 0; i < this->size(); i++) {
		sum += this->commanders()[i].calculateSumFightingSkill();
	}

	return sum;
}

size_t General::calculateArmyAverageFightingSkill() const{
	return calculateArmySumFightingSkill() / this->size();
}







void General::copyDynamic(const General& general) {
	this->_commanders = new Commander[general.capacity()];
	copyCommanders(this->_commanders, general.commanders(), general.size());
	setString(this->_description, general.description());
}

void General::moveDynamic(General&& general){
	this->_commanders = general._commanders;
	general._commanders = nullptr;

	this->_description = general._description;
	general._description = nullptr;

}

void General::copyCommanders(Commander*& dest, const Commander* src, size_t size){
	for (size_t i = 0; i < size; i++){
		dest[i] = src[i];
	}
}


void General::free(){
	delete[] this->_commanders;
	delete[] this->_description;
	
}













