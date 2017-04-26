/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.16.2017
 *
 * Description: This is the input validator function that can
 * be reused for other applications.  Currently it hosts a
 * number validator which ensures that the user input a valid
 * integer and not something else, like a string or character
 * value that could cause an infinite loop in something like
 * a Cin call.  The function prompts the user for input, checks
 * to see if it is valid, if it is then it is returned to the
 * user, otherwise it will loop until it receives valid input.
**************************************************************/

#include <iostream>
#include <limits>

#include "validator.hpp"
int numberValidator() {
	int userInput;
	do {

		if (!std::cin) {
			// Clear the error for the cin stream
			std::cin.clear();

			// Remove whatever is stored in the buffer up to the newline symbol at the end of the input buffer
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "I'm sorry, that was an invalid response, please try your response again." << std::endl;
		}

		std::cin >> userInput;

	} while (!std::cin);

	return userInput;
}