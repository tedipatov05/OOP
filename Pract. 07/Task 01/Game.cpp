#include "Game.h"

#include <algorithm>
#include <iostream>
#pragma warning(disable:4996)

namespace Utils {
	void setString(char*& destination, const char* source) {

		size_t len = strlen(source);
		destination = new char[len + 1];
		if (len != 0)
		{
			strcpy(destination, source);

		}
	}

	constexpr double EPSILON = 0.000000000000000000000001;

}



// --------- setters -----------------


void Game::setHeroes(const char** heroes, int heroCount){
	if (heroCount == 0){
		return;
	}

	this->heroes = new char* [heroCount];
	for (size_t i = 0; i < heroCount; i++){
		Utils::setString(this->heroes[i], heroes[i]);
	}

}

void Game::setPrice(double price){
	this->price = price;
	
}

void Game::setTitle(const char* title){
	Utils::setString(this->title, title);
}

// ------ getters -------

const char* Game::getTitle() const{
	return this->title;
}

double Game::getPrice() const{
	return this->price;
}

const char** Game::getHeroes(int& count) const{

	count = this->heroCount;
	return (const char**)this->heroes;
}



// ---------- BIG Four helpful functions

void Game::copyFrom(const Game& other){

	setHeroes((const char**)other.heroes, other.heroCount);
	setPrice(other.price);
	this->heroCount = other.heroCount;
	Utils::setString(this->title, other.title);
}

void Game::free(){
	delete[] this->title;

	for (size_t i =0; i < heroCount; i++){
		delete[] this->heroes[i];
	}

	delete[] heroes;
}

// -------- Functionality ------------------

bool Game::isFree() const{
	return (this->price - 0.0) < Utils::EPSILON;
}

void Game::print() const{
	std::cout << this->title << " " << this->price << "$" << std::endl;
	std::cout << "Heroes: " << std::endl;

	for (size_t i = 0; i < heroCount-1; i++){
		std::cout << this->heroes[i] << ", ";
	}

	std::cout << this->heroes[heroCount - 1] << std::endl;
}

// ----------- BIG Four ------------------------

Game::Game(const char* title, double price, const char** heroes, int heroCount){
	setTitle(title);
	setPrice(price);
	setHeroes(heroes, heroCount);
	this->heroCount = heroCount;
}

Game::Game(const Game& other){
	copyFrom(other);
}

Game& Game::operator=(const Game& other){
	if (this != &other){
		free();
		copyFrom(other);

	}

	return *this;
}

Game::~Game(){
	free();
}

// ------------------ Files functions ------------------------

void Game::saveInFile(std::ofstream& ofs) const{

	if (!ofs.is_open()){
		return;
	}

	ofs << strlen(this->title) << std::endl;
	ofs << this->title << std::endl;
	ofs << this->price << std::endl;
	ofs << this->heroCount << std::endl;

	for (size_t i = 0; i < heroCount; i++){

		ofs << strlen(this->heroes[i]) << std::endl;
		ofs << this->heroes[i] << std::endl;
	}
}

void Game::loadFromFile(std::ifstream& ifs){
	//free();

	size_t lenTitle;
	ifs >> lenTitle;
	ifs.ignore();

	char* buffer = new char[lenTitle + 1];
	ifs.getline(buffer, lenTitle+1);
	buffer[lenTitle] = '\0';
	setTitle(buffer);

	delete[] buffer;
	//ifs.ignore();

	double price = 0;
	ifs >> price;
	setPrice(price);

	ifs >> this->heroCount;
	this->heroes = new char* [heroCount];
	for (size_t i = 0; i < heroCount; i++){
		size_t heroLen = 0;
		ifs >> heroLen;
		ifs.ignore();

		char* hero = new char[heroLen + 1];
		ifs.getline(hero, heroLen+1);
		hero[heroLen] = '\0';
		Utils::setString(this->heroes[i], hero);

		delete[] hero;
	}

}













