#pragma once
#include <windows.h> 
#include <iostream>

using namespace std;

class ConsoleUtils {
private:
	static void removeScrollbar();
public:
	static void initConsole();
	static void printFrame();
	static void clearConsole();
	static void gotoxy(int column, int line);
};