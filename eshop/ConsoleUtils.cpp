#include "ConsoleUtils.h"
void ConsoleUtils::removeScrollbar()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, new_size);
}
void ConsoleUtils::initConsole() {
	int width = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);

	//Assigning variables for MoveWindows parameters
	int windowWidth = 650;		//--- Used as a parameter to specify the width of the console window (MoveWindows int nWidth)
	int windowHeight = 400;		//--- Used as a parameter to specify the height of the console window (MoveWindows int nHeight)
	int newWidth = (width - windowWidth) / 2;		//--- Used as a parameter to center the console window horizontally (MoveWindows int x)
	int newHeight = ((height - windowHeight) / 2) - 150;		//--- Used as a parameter to center the console window vertically (MoveWindows int y)

																//Getting the console window handle
	HWND hWnd = GetConsoleWindow();

	//Declaring the function
	BOOL WINAPI MoveWindow(_In_ HWND hWnd, _In_ int NewWidth, _In_ int NewHeight, _In_ int WindowWidth, _In_ int WindowHeight, _In_ BOOL bRepaint);

	MoveWindow(hWnd, newWidth, newHeight, windowWidth, windowHeight, TRUE);
	removeScrollbar();
	SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}
void ConsoleUtils::printFrame() {

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	gotoxy(0, 0); // top-left corner

	int color = 11;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < 1; j++) {
			gotoxy(i, j);
			printf("%c", 205);
		}
	}
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < rows; j++) {
			gotoxy(i, j);
			printf("%c", 186);
		}
	}
	for (int i = columns - 1; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			gotoxy(i, j);
			printf("%c", 186);
		}
	}
	gotoxy(0, 0);
	printf("%c", 201);
	gotoxy(columns-1, 0);
	printf("%c", 187);
	gotoxy(0, 0);
}
void ConsoleUtils::clearConsole()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// you can loop k higher to see more color choices
	SetConsoleTextAttribute(hConsole, 14);
	system("cls");
	printFrame();
	SetConsoleTextAttribute(hConsole, 14);
}

void ConsoleUtils::gotoxy(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}

