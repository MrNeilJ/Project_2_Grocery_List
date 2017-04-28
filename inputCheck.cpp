//
// Created by Neil on 4/27/2017.
//

#include <iostream>
#include <limits>
#include "inputCheck.hpp"


/**************************************************************
 *  STRING VALIDATORS
**************************************************************/
std::string getString() {
	std::string tempString;
	std::getline(std::cin, tempString);
	return tempString;
}

std::string getWord() {
	std::string tempWord;
	std::getline(std::cin, tempWord);
	return tempWord;
}


/**************************************************************
 *  CHAR VALIDATORS
**************************************************************/
char getChar() {
	char tempChar = getchar();

	// Clear the error for the cin stream
	std::cin.clear();

	// Remove whatever is stored in the buffer up to the newline symbol at the end of the input buffer
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return  tempChar;
}

char getChar(int clear) {
	int tempChar;
	if (clear == 1) {
		tempChar = getchar();

		// Clear the error for the cin stream
		std::cin.clear();

		// Remove whatever is stored in the buffer up to the newline symbol at the end of the input buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return tempChar;
	}
	else {
		tempChar = getchar();
		// Clear the error for the cin stream
		std::cin.clear();

		// Remove whatever is stored in the buffer up to the newline symbol at the end of the input buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return  tempChar;

	}

}


/**************************************************************
 *  NUMBER VALIDATORS
**************************************************************/
int getInt() {
	int tempInt;

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

	// Clear the error for the cin stream
	std::cin.clear();

	// Remove whatever is stored in the buffer up to the newline symbol at the end of the input buffer
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return tempInt;
}

float getFloat() {
	float tempFloat;

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

	// Clear the error for the cin stream
	std::cin.clear();

	// Remove whatever is stored in the buffer up to the newline symbol at the end of the input buffer
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return tempFloat;
}

/**************************************************************
 *  STRING MANIPULATORS
**************************************************************/
std::string lowerCase(std::string &userString) {
	for (int i = 0; i < userString.length(); i++) {
		tolower(userString[i]);
	}
}

std::string capitalize(std::string userString) {
	for (int i = 0; i < userString.length(); i++) {
		tolower(userString[i]);
	}
	toupper(userString[0]);
}


