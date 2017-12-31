#include "IOUtils.h"

void IOUtils::cleanCin()
{
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
string IOUtils::readString() {
	string input;
	getline(std::cin, input);
	return input;
}

int IOUtils::readInt() {
	string input;
	getline(std::cin, input);
	bool validationError = false;
	int val;
	try {
		val = std::stoi(input);
	}
	catch (...) {
		throw exception("Incorrect integer!");
	}
	return val;
}

bool IOUtils::readCondition()
{
	string input;
	bool val;
	getline(std::cin, input);
	val = false;
	if (input == "y" || input == "Y") {
		val = true;
	}
	return val;
}
