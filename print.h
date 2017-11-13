/*
 * print.h
 *
 *  Created on: Nov 13, 2017
 *      Author: eran
 */

#ifndef PRINT_H_
#define PRINT_H_

#include <iostream>

template<typename T>
void print(const T & value) {
	std::cout << value << std::endl;
}

template<typename T, typename U, typename ... TS>
void print(const T & value1, const U & value2, TS ... args) {
	std::cout << value1 << " ";
	print(value2, args...);
}

#endif /* PRINT_H_ */
