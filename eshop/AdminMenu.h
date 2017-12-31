#pragma once 
#include <windows.h> 
#include <iostream>
#include <conio.h>
using namespace std;

#include "Product.h"
#include "Eshop.h"
#include "IOUtils.h"
#include "CommonMenu.h"
#include "ConfigurableProduct.h"
#include "ConsoleUtils.h"

class AdminMenu {
private:
	static Product * createProduct();
	static ConfigurableProduct * createConfigurableProduct();
	static void createProductMenu();
	static void displayProductMenu();
	static void deleteProductMenu();
	static void deleteProduct();
public:
	static void modifyProduct();
	static void modifyProductMenu();
	static void menu();
};