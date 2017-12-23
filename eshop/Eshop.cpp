#include "Eshop.h" 

Eshop* Eshop::instance = 0;

Eshop * Eshop::getInstance()
{
	if (!instance)
		instance = new Eshop;
	return instance;
}

vector<Product*>* Eshop::getProducts()
{
	return &products;
}

void Eshop::addProduct(Product * product)
{
	products.push_back(product);
}

Product * Eshop::findProductByNum(int no)
{
	vector<Product*>::iterator itrProducts = products.begin();
	while (itrProducts != products.end()) {
		if ((*itrProducts)->productNumber == no) {
			return (*itrProducts);
		}
		++itrProducts;
	}
	throw exception("Product does not exist!");
}

void Eshop::updateProduct(int no, Product * product)
{
	vector<Product*>::iterator itrProducts = products.begin();

	while (itrProducts != products.end()) {
		if ((*itrProducts)->productNumber == no) {

			int offset = (itrProducts - products.begin());
			products.erase(products.begin() + offset);
			products.push_back(product);
			return;
		}
		++itrProducts;
	}
	throw exception("Product does not exist!");
}

void Eshop::removeProduct(int no) {
	vector<Product*>::iterator itrProducts = products.begin();
	while (itrProducts != products.end()) {
		if ((*itrProducts)->productNumber == no) {
			products.erase(itrProducts);
			return;
		}
		++itrProducts;
	}
	throw exception("Product does not exist!");
}