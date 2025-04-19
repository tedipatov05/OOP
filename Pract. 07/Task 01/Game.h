#pragma once
#include <fstream>
#pragma warning(disable:4996)


class Game {
private:

	char* title;
	double price;
	char** heroes;
	int heroCount;

	void setHeroes(const char** heroes, int heroCount);

	void copyFrom(const Game& other);
	void free();

public:
	Game() = default;
	Game(const char* title, double price, const char** heroes, int heroCount);
	Game(const Game& other);
	Game& operator=(const Game& other);
	~Game();

	void setPrice(double price);
	void setTitle(const char* title);

	const char* getTitle() const;
	double getPrice() const;
	const char** getHeroes(int& count) const;

	bool isFree() const;
	void saveInFile(std::ofstream& ofs) const;
	void loadFromFile(std::ifstream& ifs);

	void print() const;

};

