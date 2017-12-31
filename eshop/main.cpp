// eshop.cpp : Defines the entry point for the console application.
//

#include <conio.h>
#include <stdlib.h>
#include <windows.h> 
#include "ConsoleUtils.h"
#include "MainMenu.h" 


int main() {
	ConsoleUtils::initConsole();
	ConsoleUtils::clearConsole();
	MainMenu::intro();
	MainMenu::menu();

	return 0; /* use Ctrl+C, never returns */
}