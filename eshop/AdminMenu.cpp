#include "AdminMenu.h"

Product* AdminMenu::createProduct()
{
	Product * product = new Product;
	cout << "\n\t" << "Please enter the product no. of the product: ";
	try {
		product->productNumber = IOUtils::readInt();
	}
	catch (exception) {
		throw exception("Incorrect product number!");
	}
	cout << "\n\t" << "Please enter the name of the product: ";
	try {
		product->name = IOUtils::readString();
	}
	catch (exception) {
		throw exception("Incorrect name!");
	}
	cout << "\n\t" << "Please enter the price of the product: ";
	try {
		product->price = IOUtils::readInt();
	}
	catch (exception) {
		throw exception("Incorrect price!");
	}
	cout << "\n\t" << "Please enter the discount (%): ";
	try {
		product->discount = IOUtils::readInt();
	}
	catch (exception) {
		throw exception("Incorrect discount!");
	}
	return product;
}

ConfigurableProduct* AdminMenu::createConfigurableProduct()
{
	string input;

	ConfigurableProduct * product = new ConfigurableProduct;
	Product * baseProduct = createProduct();
	product->productNumber = baseProduct->productNumber;
	product->name = baseProduct->name;
	product->price = baseProduct->price;
	product->discount = baseProduct->discount;

	cout << "\n\t" << "The product is solid? (y/n): ";
	product->solid = IOUtils::readCondition();

	cout << "\n\t" << "Width: ";
	try {
		product->width = IOUtils::readInt();
	}
	catch (exception) {
		throw exception("Incorrect width!");
	}

	cout << "\n\t" << "Height: ";
	try {
		product->height = IOUtils::readInt();
	}
	catch (exception) {
		throw exception("Incorrect height!");
	}

	cout << "\n\t" << "Depth: ";
	try {
		product->depth = IOUtils::readInt();
	}
	catch (exception) {
		throw exception("Incorrect depth!");
	}

	cout << "\n\t" << "Mass: ";
	try {
		product->mass = IOUtils::readInt();
	}
	catch (exception) {
		throw exception("Incorrect mass!");
	}
	return product;
}

void AdminMenu::createProductMenu()
{
	Product * product;
	try {
		cout << "\n\n\n\t" << "You want to create a configurable product ? (y/n): ";

		if (IOUtils::readCondition()) {
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
	ConsoleUtils::clearConsole();
	cout << "\n\n\n\t" << "Product No. : ";
	try {
		num = IOUtils::readInt();
	}
	catch (exception) {
		throw exception("Incorrect product number!");
	}
	CommonMenu::productHeader();
	try {
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
	ConsoleUtils::clearConsole();
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
	int num;
	try {
		num = IOUtils::readInt();
	}
	catch (exception) {
		throw exception("Incorrect product number!");
	}
	Eshop::getInstance()->removeProduct(num);
	cout << "\n\t" << "Product deleted!";
	_getch();
}

void AdminMenu::modifyProduct()
{
	int num;
	try {
		num = IOUtils::readInt();
	}
	catch (exception) {
		throw exception("Incorrect product number!");
	}

	cout << "\n\t" << "You want to create a configurable product ? (y/n)";

	bool conf = IOUtils::readCondition();
	cout << "\n\t" << "Please Enter the new details of product: " << endl;

	CommonMenu::productHeader();
	CommonMenu::displayProduct(num);

	Product * product = nullptr;
	if (conf) {
		product = createConfigurableProduct();
	}
	else {
		product = createProduct();
	}
	Eshop::getInstance()->updateProduct(num, product);
	cout << "\n\t" << "Product updated!";
	_getch();

}
void AdminMenu::modifyProductMenu()
{
	ConsoleUtils::clearConsole();
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
	ConsoleUtils::clearConsole();
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
		ConsoleUtils::clearConsole();
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