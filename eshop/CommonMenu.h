#pragma once
#include <windows.h> 
#include <iostream>
#include <conio.h>

using namespace std;

#include "Eshop.h"
#include "ConfigurableProduct.h"
#include "ConsoleUtils.h"

class CommonMenu {
public:
	static void priceList();
	static void displayProduct(Product * prod);
	static void displayProduct(int num);
	static void productHeader();
};
