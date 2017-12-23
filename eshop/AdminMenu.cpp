#include "AdminMenu.h"

Product* AdminMenu::createProduct()
{
	Product * product = new Product;
	cout << "\n\t" << "Please enter the product no. of the product: ";
	cin >> product->productNumber;
	if (cin.fail())
	{
		IOUtils::cleanCin();
		throw exception("Incorrect product number!");
	}
	cout << "\n\t" << "Please enter the name of the product: ";
	cin >> product->name;
	if (cin.fail())
	{
		IOUtils::cleanCin();
		throw exception("Incorrect name!");
	}
	cout << "\n\t" << "Please enter the price of the product: ";
	cin >> product->price;
	if (cin.fail())
	{
		IOUtils::cleanCin();
		throw exception("Incorrect price!");
	}
	cout << "\n\t" << "Please enter the discount (%): ";
	cin >> product->discount;
	if (cin.fail())
	{
		IOUtils::cleanCin();
		throw exception("Incorrect discount!");
	}
	return product;
}

ConfigurableProduct* AdminMenu::createConfigurableProduct()
{
	ConfigurableProduct * product = new ConfigurableProduct;
	Product * baseProduct = createProduct();
	product->productNumber = baseProduct->productNumber;
	product->name = baseProduct->name;
	product->price = baseProduct->price;
	product->discount = baseProduct->discount;

	char ch = 'Y';
	cout << "\n\t" << "The product is solid? (y/n): ";
	cin >> ch;
	product->solid = false;
	if (ch == 'y' || ch == 'Y') {
		product->solid = true;
	}

	cout << "\n\t" << "Width: ";
	cin >> product->width;

	if (cin.fail())
	{
		IOUtils::cleanCin();
		throw exception("Incorrect width!");
	}


	cout << "\n\t" << "Height: ";
	cin >> product->height;

	if (cin.fail())
	{
		IOUtils::cleanCin();
		throw exception("Incorrect height!");
	}

	cout << "\n\t" << "Depth: ";
	cin >> product->depth;

	if (cin.fail())
	{
		IOUtils::cleanCin();
		throw exception("Incorrect depth!");
	}


	cout << "\n\t" << "Mass: ";
	cin >> product->mass;

	if (cin.fail())
	{
		IOUtils::cleanCin();
		throw exception("Incorrect mass!");
	}
	return product;
}

void AdminMenu::createProductMenu()
{
	Product * product;
	try {
		char ch = 'Y';
		cout << "\n\n\n\t" << "You want to create a configurable product ? (y/n): ";
		cin >> ch;
		if (ch == 'y' || ch == 'Y') {
			product = createConfigurableProduct();
		}
		else {
			product = createProduct();
		}
	}
	catch (exception& e) {
		cout << "\n\t" << e.what();
		_getch();
		return;
	}
	Eshop::getInstance()->addProduct(product);
	cout << "\n\n\t" << "The product has been created!";
	_getch();
}


void AdminMenu::displayProductMenu()
{
	int num;
	system("cls");
	cout << "\n\n\n\t" << "Product No. : ";
	cin >> num;
	try {
		if (cin.fail())
		{
			IOUtils::cleanCin();
			throw exception("Incorrect product number");
		}
		CommonMenu::productHeader();
		CommonMenu::displayProduct(num);
	}
	catch (exception& e) {
		cout << "\n\t" << e.what();
		_getch();
		return;
	}
	_getch();
}
void AdminMenu::deleteProductMenu()
{
	system("cls");
	cout << "\n\n\n\t" << "Delete product";
	cout << "\n\n\t" << "Please enter the product no.: ";
	try {
		deleteProduct();
	}
	catch (exception& e) {
		cout << "\n\t" << e.what();
		_getch();
		return;
	}
}
void AdminMenu::deleteProduct()
{
	int no;
	cin >> no;
	Eshop::getInstance()->removeProduct(no);
	cout << "\n\t" << "Product deleted!";
	_getch();
}

void AdminMenu::modifyProduct()
{
	int no;
	cin >> no;

	char ch = 'Y';
	cout << "\n\t" << "You want to create a configurable product ? (y/n)";
	cin >> ch;
	cout << "\n\t" << "Please Enter the new details of product: " << endl;

	CommonMenu::productHeader();
	CommonMenu::displayProduct(no);

	Product * product = nullptr;
	if (ch == 'y' || ch == 'Y') {
		product = createConfigurableProduct();
	}
	else {
		product = createProduct();
	}
	Eshop::getInstance()->updateProduct(no, product);
	cout << "\n\t" << "Product updated!";
	_getch();
	
}
void AdminMenu::modifyProductMenu()
{
	system("cls");
	cout << "\n\n\n\t" << "To nodify ";
	cout << "\n\n\t" << "Please enter the product nunmber: ";
	try {
		modifyProduct();
	}
	catch (exception& e) {
		cout << "\n\t" << e.what();
		_getch();
		return;
	}
}
void AdminMenu::menu()
{
	system("cls");
	char ch2;
	cout << "\n\n\n\t" << "ADMIN MENU";
	cout << "\n\n\t" << "1.CREATE PRODUCT";
	cout << "\n\n\t" << "2.DISPLAY ALL PRODUCTS";
	cout << "\n\n\t" << "3.QUERY ";
	cout << "\n\n\t" << "4.MODIFY PRODUCT";
	cout << "\n\n\t" << "5.DELETE PRODUCT";
	cout << "\n\n\t" << "6.BACK TO MAIN MENU";
	cout << "\n\n\t" << "Please Enter Your Choice (1-7) ";
	ch2 = _getche();
	switch (ch2)
	{
	case '1':
		system("cls");
		createProductMenu();
		break;
	case '2':
		CommonMenu::priceList();
		_getch();
		break;
	case '3':
		displayProductMenu();
		break;
	case '4':
		modifyProductMenu();
		break;
	case '5':
		deleteProductMenu();
		break;
	case '6':
		break;
	default:cout << "\a";
		menu();
	}
}