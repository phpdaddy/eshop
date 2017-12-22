#include "Eshop.h" 

Eshop* Eshop::instance = 0;

Eshop * Eshop::getInstance()
{
	if (!instance)
		instance = new Eshop;
	return instance;
}

vector<Product*> Eshop::getProducts()
{
	return products;
}

void Eshop::addProduct(Product * product)
{
	products.push_back(product);
}