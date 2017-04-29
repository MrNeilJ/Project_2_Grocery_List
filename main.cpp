/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.30.2017
 *
 * Description: This is the main file for my grocery list
 * program.  In here we create the basic flow of the application
 * using menus to help guide the customer.  We greet the customer
 * and then allow them to add items to their list, update the
 * list, remove items, view the list, and even checkout when
 * they are satisfied with their list.
 **************************************************************/

#include <iostream>
#include "menuMaker.hpp"
#include "List.hpp"
#include "inputCheck.hpp"

int main() {
	// Welcome the user to the application
	std::cout << "*******************************************" << std::endl;
	std::cout << "*              GROCERY LIST               *" << std::endl;
	std::cout << "*******************************************" << std::endl;

	std::cout << "Welcome to the Grocery list application!" << std::endl;
	std::cout << "In this application you can create a grocery list for the next time you shop!\n" << std::endl;

	int userChoice = 0;
	menuMaker mainMenu("\nWhat would you like to do?",
					   "Add an item",
					   "Remove an item",
					   "View your list",
					   "Checkout",
					   "Quit");

	// Create the list object
	List myList;

	// Loop through the menu until the user has chosen to quit the program or checks out
	do  {
		mainMenu.prompt();
		userChoice = mainMenu.getResponse();

		// If the user selects 1, then add the item they type in into the list
		if(userChoice == 1) {
			myList.addItem();
		}
		// If they select 2, allow them to decide which item they would like to remove
		else if (userChoice == 2) {
			myList.removeItem();
		}
		// If they select 3, then display the list in an easy to read format
		else if (userChoice == 3) {
			myList.displayList();
		}
		// If they choose 4, take the list at its current state and check out
		else if (userChoice == 4) {
			myList.checkOut();
			return 0;
		}
		// If they choose 5, then end the program
		else if (userChoice == 5) {
			std::cout << "Now leaving the Grocery List Program, have a great day!" << std::endl;
			return 0;
		}
		// Fail-safe in case they type in something that does not match the above criteria
		else {
			std::cout << "Invalid option, please try again.\n" << std::endl;
		}
	} while (userChoice != 5);

	return 0;
}