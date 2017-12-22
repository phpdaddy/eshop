#pragma once

#include <windows.h> 

class ConsoleUtils {
private:
	static void removeScrollbar();
public:
	static void initConsole();
	static void gotoxy(int column, int line);
};