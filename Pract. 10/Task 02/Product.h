#pragma once
#include <istream>

class Product
{

public:
	Product();
	Product(const char* name);
	Product(const Product& product);
	Product(Product&& product) noexcept;
	Product& operator=(const Product& product);
	Product& operator=(Product&& product) noexcept;
	~Product();

	const char* name() const;

	friend std::istream& operator>>(std::istream& is, Product& product);

private:
	char* _name;

	void free();
	void copyDynamic(const char* name);
	void copyMove(Product&& product);
};

bool operator==(const Product& lhs, const Product& rhs);
