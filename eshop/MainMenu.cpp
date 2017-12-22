#include "MainMenu.h"

void MainMenu::intro()
{
	system("cls");
	ConsoleUtils::gotoxy(34, 5);
	cout << "SUPER MARKET";
	ConsoleUtils::gotoxy(34, 7);
	cout << "BILLING";
	ConsoleUtils::gotoxy(34, 9);
	cout << "PROJECT";
	ConsoleUtils::gotoxy(28, 13);
	cout << "MADE BY : VLADYSLAV FROLOV";
	ConsoleUtils::gotoxy(25, 15);
	cout << "SCHOOL : SOUTH BOHEMIAN UNIVERSITY";
	_getch();
}

void MainMenu::menu() {
	char ch;
	do
	{
		system("cls");
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t01. CUSTOMER";
		cout << "\n\n\t02. ADMINISTRATOR";
		cout << "\n\n\t03. EXIT";
		cout << "\n\n\tPlease Select Your Option (1-3) ";
		ch = _getche();
		switch (ch)
		{
		case '1':
			CustomerMenu::menu();
			_getch();
			break;
		case '2':
			AdminMenu::menu();
			break;
		case '3':exit(0);
		default:cout << "\a";
		}
	} while (ch != '3');
}