#pragma once 
#include <windows.h> 
#include <iostream>
#include <conio.h>
using namespace std;

#include "ConsoleUtils.h"
#include "AdminMenu.h"
#include "CustomerMenu.h"

class MainMenu {
public:
	static void intro();
	static void menu();
};