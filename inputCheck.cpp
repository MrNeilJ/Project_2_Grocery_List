//
// Created by Neil on 4/27/2017.
//

#include <iostream>
#include <limits>
#include "inputCheck.hpp"


/**************************************************************
 *  STRING VALIDATORS
**************************************************************/
std::string inputCheck::getString() {
	std::getline(std::cin, tempString);
	return tempString;
}

std::string inputCheck::getWord() {

	return tempWord;
}


/**************************************************************
 *  CHAR VALIDATORS
**************************************************************/
char inputCheck::getChar() {
	tempChar = getchar();
	return  tempChar;
}

char inputCheck::getChar(int clear) {
	if (clear == 1) {
		tempChar = getchar();
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		return tempChar;
	}
	else {
		tempChar = getchar();

		return  tempChar;
	}

}


/**************************************************************
 *  NUMBER VALIDATORS
**************************************************************/
int inputCheck::getInt() {
	do {

		if (!std::cin) {
			// Clear the error for the cin stream
			std::cin.clear();

			// Remove whatever is stored in the buffer up to the newline symbol at the end of the input buffer
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "I'm sorry, that was an invalid response, please try your response again." << std::endl;
		}

		std::cin >> tempInt;

	} while (!std::cin);

	return tempInt;
}

float inputCheck::getFloat() {
	do {

		if (!std::cin) {
			// Clear the error for the cin stream
			std::cin.clear();

			// Remove whatever is stored in the buffer up to the newline symbol at the end of the input buffer
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "I'm sorry, that was an invalid response, please try your response again." << std::endl;
		}

		std::cin >> tempFloat;

	} while (!std::cin);

	return tempFloat;
}
