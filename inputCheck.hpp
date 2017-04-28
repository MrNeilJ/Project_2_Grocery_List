//
// Created by Neil on 4/27/2017.
//

#ifndef PROJECT_2_INPUTCHECK_HPP
#define PROJECT_2_INPUTCHECK_HPP

#include <string>

// String validators
std::string getString();		// Returns a string characters (can include spaces)
std::string getWord();			// Returns a single word and has the option to clear the istream

// Char validators
char getChar();					// Returns a single character
char getChar(int);

// Number validators
int getInt();					// Confirms user input was an int and returns that value
float getFloat();				// Confirms user input was a float and returns that value

#endif //PROJECT_2_INPUTCHECK_HPP
