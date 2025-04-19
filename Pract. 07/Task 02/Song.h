#pragma once
#include <iostream>


class Song {
private:
	char* name;
	unsigned duration;
	uint8_t genre;
	uint8_t* content;
	size_t size;

	uint8_t encodeGenre(const char* genre);

	void copyForm(const Song& other);
	void free();

public: 

	Song() = default;
	Song(const char* name, unsigned duration, const char* genre, const char* filename);
	Song(const Song& other);
	Song& operator=(const Song& other);
	~Song();

	void setName(const char* name);
	void setDuration(unsigned duration);

	uint8_t getGenre() const;

	void loadContent(const char* filename);
	void saveContent(const char* filename) const;

	void mixWith(Song& other);
	void modifyRythm(int k);

	void printContent() const;


};
