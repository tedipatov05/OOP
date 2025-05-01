#pragma once
#include "Collection.h"
class NormalCollection :public Collection{

public:

	NormalCollection(size_t capacity);

	void add(int number) override;
	void remove(int number) override;
	size_t getSize() const override;
	bool contains(int number) const override;

private:

	void resize() {  };
	size_t capacity;
};

