#include "CustomerMenu.h"

void CustomerMenu::printInvoice(vector<Order*> orders) {

	float total = 0;
	cout << "\n\n\t" << "********************************INVOICE*****************************" << "\n";
	cout << "\n\t" << "P.no.\tName\tQuantity \tPrice \tAmount \tAmount after discount" << "\n";

	vector<Product*>* products = Eshop::getInstance()->getProducts();

	vector<Product*>::iterator itrProducts = products->begin();
	vector<Order*>::iterator itrOrders = orders.begin();
	while (itrOrders != orders.end()) {
		while (itrProducts != products->end()) {
			if ((*itrProducts)->productNumber == (*itrOrders)->productNumber) {
				float amt, damt = 0;
				amt = (*itrProducts)->price*(*itrOrders)->quantity;
				damt = amt - (amt*(*itrProducts)->discount / 100);
				cout << "\n\t" << (*itrProducts)->productNumber << "\t" << (*itrProducts)->name
					<< "\t" << (*itrOrders)->quantity << "\t\t" << (*itrProducts)->price << "\t" << amt << "\t\t" << damt;
				total += damt;
			}
			++itrProducts;
		}
		++itrOrders;
	}
	cout << "\n\n\t" << "TOTAL = " << total;
}
void CustomerMenu::menu()
{
	int c = 0;
	vector<Order*> orders;
	do {
		ConsoleUtils::clearConsole();
		CommonMenu::priceList();
		cout << "\n\t" << "============================";
		cout << "\n\t" << "Place your order";
		cout << "\n\t" << "============================" << "\n";
		Order *order = new Order;
		cout << "\n\t" << "Enter the product number: ";
		try {
			try {
				order->productNumber = IOUtils::readInt();
			}
			catch (exception) {
				throw exception("Incorrect product number!");
			}
			vector<Product*>* products = Eshop::getInstance()->getProducts();

			vector<Product*>::iterator itrProducts = products->begin();
			Product * p = Eshop::getInstance()->findProductByNum(order->productNumber);
			cout << "\n\t" << "Quantity: ";
			try {
				order->quantity = IOUtils::readInt();
			}
			catch (exception) {

				throw exception("Incorrect quantity!");
			}
		}
		catch (exception& e) {
			cout << "\n\t" << e.what();
			_getch();
			return;
		}
		orders.push_back(order);
		cout << "\n\t" << "Do you want to order another product ? (y/n)";
	} while (IOUtils::readCondition());
	cout << "\n\t" << "Thank you for placing the order";
	_getch();

	ConsoleUtils::clearConsole();

	ofstream *out = new ofstream("out.txt");
	std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
	std::cout.rdbuf(out->rdbuf()); //redirect std::cout to out.txt!
	printInvoice(orders);
	std::cout.rdbuf(coutbuf);
	printInvoice(orders);
	_getch();
}
