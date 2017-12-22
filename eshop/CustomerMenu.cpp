#include "CustomerMenu.h"

void CustomerMenu::printInvoice(vector<Order*> orders) {

	float total = 0;
	cout << "\n\n\t" << "********************************INVOICE*****************************" << "\n";
	cout << "\n\t" << "P.no.\tName\tQuantity \tPrice \tAmount \tAmount after discount" << "\n";

	vector<Product*> products = Eshop::getInstance()->getProducts();

	vector<Product*>::iterator itrProducts = products.begin();
	vector<Order*>::iterator itrOrders = orders.begin();
	while (itrOrders != orders.end()) {
		while (itrProducts != products.end()) {
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
	char ch = 'Y';
	do {
		system("cls");
		CommonMenu::priceList();
		cout << "\n\t" << "============================";
		cout << "\n\t" << "Place your order";
		cout << "\n\t" << "============================" << "\n";
		Order *order = new Order;
		cout << "\n\t" << "Enter the product number: ";
		try {
			cin >> order->productNumber;
			if (cin.fail())
			{
				IOUtils::cleanCin();
				throw exception("Incorrect product number!");
			}
			vector<Product*> products = Eshop::getInstance()->getProducts();

			vector<Product*>::iterator itrProducts = products.begin();
			Product * p = nullptr;
			while (itrProducts != products.end()) {
				if ((*itrProducts)->productNumber == order->productNumber) {
					p = (*itrProducts);
					break;
				}
				++itrProducts;
			}
			if (p == nullptr) {
				throw exception("Product does not exist!");
			}
			cout << "\n\t" << "Quantity: ";
			cin >> order->quantity;
			if (cin.fail())
			{
				IOUtils::cleanCin();
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
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << "\n\t" << "Thank you for placing the order";
	_getch();
	system("cls");


	ofstream *out = new ofstream("out.txt");
	std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
	std::cout.rdbuf(out->rdbuf()); //redirect std::cout to out.txt!
	printInvoice(orders);
	std::cout.rdbuf(coutbuf);
	printInvoice(orders);
	_getch();
}
