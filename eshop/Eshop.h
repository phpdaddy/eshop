#pragma once
#include <vector>
using namespace std;

#include "Product.h"

class Eshop
{
private:
	vector<Product*> products;

	static Eshop *instance;
	Eshop() { }
public:
	static Eshop *getInstance();
	vector<Product*> getProducts();
	void addProduct(Product* product);
};
