#include "CommonMenu.h"

void CommonMenu::productHeader() {
	cout << "\t" << "=============================================================" << "\n";
	cout << "\t" << "P.no.\t\tName\t\t" << "Price\t\t" << "Extra" << "\n";
	cout << "\t" << "=============================================================" << "\n";
}

void CommonMenu::priceList()
{
	system("cls");
	cout << "\n\n\t" << "Product menu" << "\n\n";
	productHeader();

	vector<Product*> *products = Eshop::getInstance()->getProducts();
	vector<Product*>::iterator itrProducts = products->begin();
	while (itrProducts != products->end()) {
		displayProduct(*itrProducts);
		++itrProducts;
	}

}
void CommonMenu::displayProduct(Product * prod) {
	if (ConfigurableProduct* conf = dynamic_cast<ConfigurableProduct*>(prod))
	{
		cout << "\t" << conf->productNumber << "\t\t" << conf->name << "\t\t" << conf->price
			<< "\t\t" << (conf->solid ? "Solid " : "") << conf->width << "x" << conf->height << "x" << conf->depth
			<< " " << conf->mass << "kg" << endl;
	}
	else {
		cout << "\t" << (prod)->productNumber << "\t\t" << (prod)->name << "\t\t" << (prod)->price;
	}
	return;
}

void CommonMenu::displayProduct(int num) {
	displayProduct(Eshop::getInstance()->findProductByNum(num));
}