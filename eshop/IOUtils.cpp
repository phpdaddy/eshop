#include "IOUtils.h"

void IOUtils::cleanCin()
{
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
