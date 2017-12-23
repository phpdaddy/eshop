#pragma once

#include <string> 

class Product {
public:
	int productNumber;
	std::string name;
	float price;
	float discount;

	virtual ~Product() {}
};
