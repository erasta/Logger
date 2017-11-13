//============================================================================
// Name        : example.cpp
// Author      : Eran Geva
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Logger.h"

int main() {
	LOGPOS;
	Logger::log("hello", "world", 1234);
	return 0;
}
