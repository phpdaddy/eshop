#pragma once
#include <windows.h> 
#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

#include "Eshop.h"
#include "Order.h"
#include "CommonMenu.h"
#include "IOUtils.h"

class CustomerMenu {
private:
	static void printInvoice(vector<Order*> orders);
public:
	static void menu();
};
