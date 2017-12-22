#include "CommonMenu.h"

void CommonMenu::priceList()
{
	system("cls");
	vector<Product*> products = Eshop::getInstance()->getProducts();

	cout << "\n\n\t" << "Product menu" << "\n\n";
	cout << "\t" << "====================================================" << "\n";
	cout << "\t" << "P.no.\t\tName\t\t" << "Price\t\t" << "Extra" << "\n";
	cout << "\t" << "====================================================" << "\n";
	vector<Product*>::iterator itrProducts = products.begin();
	while (itrProducts != products.end()) {
		if (typeid(*itrProducts) == typeid(ConfigurableProduct))
		{
			ConfigurableProduct * conf = (Product*)(*itrProducts);
			cout << "\t" << (*itrProducts)->productNumber << "\t\t" << (*itrProducts)->name << "\t\t" << (*itrProducts)->price
				<< "\t\t" << (*itrProducts)->price << endl;
		}
		else {
			cout << "\t" << (*itrProducts)->productNumber << "\t\t" << (*itrProducts)->name << "\t\t" << (*itrProducts)->price;
		}
		++itrProducts;
	}

}
