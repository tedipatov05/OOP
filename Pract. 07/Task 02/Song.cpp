#include "Song.h"
#include <fstream>
#include <bitset>
#pragma warning(disable:4996)

namespace Utils {
	void setIntArr(uint8_t*& destination, const uint8_t* source, size_t size) {
		destination = new uint8_t[size];

		for (size_t i = 0; i < size; i++) {
			destination[i] = source[i];
		}
	}
}


Song::Song(const char* name, unsigned duration, const char* genre, const char* filename) : duration(duration) {
	setName(name);
	this->genre = encodeGenre(genre);
	loadContent(filename);
}

Song::Song(const Song& other) {
	copyForm(other);
}

Song& Song::operator=(const Song& other) {
	if (this != &other) {
		free();
		copyForm(other);
	}

	return *this;
}

Song::~Song() {
	free();
}

void Song::free() {
	delete[] name;
	delete[] content;
}

void Song::copyForm(const Song& song) {
	setName(song.name);
	this->duration = song.duration;
	this->genre = song.genre;
	this->size = song.size;
	//this->content = new uint8_t[this->size];
	Utils::setIntArr(this->content, song.content, this->size);

}

uint8_t Song::encodeGenre(const char* genre) {
	if (!genre) {
		return 0;
	}
	uint8_t genreByte = 0;
	size_t len = strlen(genre);
	for (size_t i = 0; i < len; i++) {
		switch (genre[i]) {
		case 'r': genreByte |= 1 << 0; break; // Rock
		case 'p': genreByte |= 1 << 1; break; // Pop
		case 'h': genreByte |= 1 << 2; break; // Hip-Hop
		case 'e': genreByte |= 1 << 3; break; // Electronic
		case 'j': genreByte |= 1 << 4; break; // Jazz
		}
	}
	return genreByte;
}

void Song::setName(const char* name) {
	if (!name) {
		return;
	}
	size_t len = strlen(name);
	
	if (len == 0) {
		return;
	}

	this->name = new char[len + 1];
	strcpy(this->name, name);
}

uint8_t Song::getGenre() const {
	return this->genre;
}

void Song::mixWith(Song& song) {
	int minSize = song.size < this->size ? song.size : this->size;

	for (size_t i = 0; i < minSize; i++) {
		this->content[i] ^= song.content[i];
	}
}

void Song::modifyRythm(int k) {
	if (k < 0) {
		return;
	}

	size_t len = this->size * 8;
	for (size_t i = 0; i < len; i += k) {
		size_t byteIndex = i / 8;
		size_t bitIndex = i % 8;
		this->content[byteIndex] |= (1 << (7 - bitIndex));
	}
}

void Song::setDuration(unsigned duration) {
	if (duration < 0) {
		return;
	}

	this->duration = duration;
}

void Song::loadContent(const char* filename) {
	std::ifstream ifs(filename, std::ios::binary);

	if (!ifs.is_open()) {
		return;
	}

	ifs.read((char*)&this->size, sizeof(this->size));
	this->content = new uint8_t[this->size];
	ifs.read((char*)this->content, size * sizeof(uint8_t));

	ifs.close();
}

void Song::saveContent(const char* filename) const{
	std::ofstream ofs(filename, std::ios::binary);

	if (!ofs.is_open()) {
		return;
	}

	ofs.write((const char*)&this->size, sizeof(this->size));
	ofs.write((const char*)this->content, size * sizeof(uint8_t));

}

void Song::printContent() const {
	if (size == 0) {
		return;
	}

	for (size_t i = 0; i < size; i++) {
		std::cout << std::bitset<8>(content[i]) << " ";
	}
}