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
	int Width = GetSystemMetrics(SM_CXSCREEN);
	int Height = GetSystemMetrics(SM_CYSCREEN);

	//Assigning variables for MoveWindows parameters
	int WindowWidth = 680;		//--- Used as a parameter to specify the width of the console window (MoveWindows int nWidth)
	int WindowHeight = 400;		//--- Used as a parameter to specify the height of the console window (MoveWindows int nHeight)
	int NewWidth = (Width - WindowWidth) / 2;		//--- Used as a parameter to center the console window horizontally (MoveWindows int x)
	int NewHeight = ((Height - WindowHeight) / 2) - 150;		//--- Used as a parameter to center the console window vertically (MoveWindows int y)

																//Getting the console window handle
	HWND hWnd = GetConsoleWindow();

	//Declaring the function
	BOOL WINAPI MoveWindow(_In_ HWND hWnd, _In_ int NewWidth, _In_ int NewHeight, _In_ int WindowWidth, _In_ int WindowHeight, _In_ BOOL bRepaint);

	MoveWindow(hWnd, NewWidth, NewHeight, WindowWidth, WindowHeight, TRUE);
	removeScrollbar();
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
