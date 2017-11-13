//============================================================================
// Name        : example.cpp
// Author      : Eran Geva
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Logger.h"

void func() {
	auto scope = Logger::scope("func");
}

int main() {
	Logger::log("hello", "world", 1234);
	func();
	LOGPOS;
	return 0;
}
