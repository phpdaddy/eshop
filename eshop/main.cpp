// eshop.cpp : Defines the entry point for the console application.
//

#include <conio.h>
#include <stdlib.h>
#include <windows.h> 
#include "ConsoleUtils.h"
#include "MainMenu.h" 


int main() {
	ConsoleUtils::initConsole();
	MainMenu::intro();
	//Eshop* eshop = new Eshop;
	MainMenu::menu();
}
