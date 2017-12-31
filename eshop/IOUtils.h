#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class IOUtils {
public:
	static void cleanCin();
	static string readString();
	static int readInt(); 
	static bool readCondition();
};