/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.16.2017
 *
 * Description: This is the header file for the input validator
 * function that can be reused for other applications.  Currently
 * it hosts a number validator which ensures that the user input
 * a valid integer and not something else, like a string or
 * character value that could cause an infinite loop in something
 * like a Cin call.  The function prompts the user for input, checks
 * to see if it is valid, if it is then it is returned to the
 * user, otherwise it will loop until it receives valid input.
**************************************************************/


#ifndef PROJECT_1_TRY_TWO_VALIDATOR_HPP
#define PROJECT_1_TRY_TWO_VALIDATOR_HPP


int numberValidator();

#endif //PROJECT_1_TRY_TWO_VALIDATOR_HPP
