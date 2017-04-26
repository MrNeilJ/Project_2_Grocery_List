//
// Created by Neil on 4/25/2017.
//
#include <iostream>
#include "List.hpp"
#include "menuMaker.hpp"

/***************************************************
 * CONSTRUCTORS
 ***************************************************/
List::List() {
	// Creates a blank grocery list of 4 items.
	groceryList = new Item[4];
	itemCount = 1;
}


/***************************************************
 * MEMBER FUNCTIONS
 ***************************************************/
void List::addItem(std::string userItem, std::string userType, int userQuantity, double userPrice) {
	// Use these variables as a temporary holding ground.
	std::string tempItemName;
	std::string tempType;
	int tempQuantity;
	double tempPrice;
	bool found = false;
	int i = 0;

	std::cout << "Type in the name of the product you wish to add: ";
	std::getline(std::cin, tempItemName);

	// Make sure the item they are adding isn't already in the list
	while (i < itemCount || !found){
		// If the item is found in the list notify user
		if (groceryList[i] == tempItemName) {
			found = true;
		}
		else {
			i++;
		}
	}

	if (){
		std::cout << "It appears that you already have this item on you list. Would you like to update it? ";

		// Create a menu function here
		menuMaker existingMenu("It appears that you already have this item on you list. Would you like to update it?",
								"Yes",
								"No");
		existingMenu.prompt();
		int existingResponse = existingMenu.getResponse();

		if (existingResponse == 1) {
			std::cout << "Type in the unit type";
			std::getline(std::cin, tempType);
			std::cout << std::endl;

			std::cout << "Type in the quantity in which you wish to buy: ";
			std::cin >> tempQuantity;
			std::cout << std::endl;

			std::cout << "Type in the price of each separate item: ";
			std::cin >> tempPrice;

			// Modify the existing values
			groceryList[i].setUnitType(tempType);
			groceryList[i].setQuantity(tempQuantity);
			groceryList[i].setPrice(tempPrice);

			std::cout << tempItemName << " has been updated. Thank you!" << std::endl;
		}

	}
	else {
		std::cout << "Type in the unit type";
		std::getline(std::cin, tempType);
		std::cout << std::endl;

		std::cout << "Type in the quantity in which you wish to buy: ";
		std::cin >> tempQuantity;
		std::cout << std::endl;

		std::cout << "Type in the price of each separate item: ";
		std::cin >> tempPrice;

		// Adjust the array if adding item would cause it to get outside of its current bounds

		// Add information as a new object in the grocery list
		groceryList[itemCount] = Item(tempItemName, tempType, tempQuantity, tempPrice);

		std::cout << tempItemName << " has been added. Thank you!" << std::endl;
	}

}

void List::removeItem() {

}

void List::displayList() {

}

void List::printItem() {

}
