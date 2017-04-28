#include <iostream>
#include "menuMaker.hpp"
#include "List.hpp"
#include "inputCheck.hpp"

int main() {
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
	List myList;

	do  {
		mainMenu.prompt();
		userChoice = mainMenu.getResponse();

		if(userChoice == 1) {
			myList.addItem();
		}
		else if (userChoice == 2) {
			myList.removeItem();
		}
		else if (userChoice == 3) {
			myList.displayList();
		}

		else if (userChoice == 4) {
			myList.checkOut();
			return 0;
		}
		else if (userChoice == 5) {
			return 0;
		}
		else {
			std::cout << "Invalid option, please try again.\n" << std::endl;
		}
	} while (userChoice != 5);

	return 0;
}