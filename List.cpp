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
	itemCount = 4;
	realItem = 0;

}


/***************************************************
 * MEMBER FUNCTIONS
 ***************************************************/
void List::addItem() {
	std::string tempItemName;
	std::string tempType;
	int tempQuantity;
	double tempPrice;
	bool found = false;
	int i = 0;

	std::cout << "Type in the name of the product you wish to add: ";
	std::cin >> tempItemName;

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

	if (found){
		std::cout << "It appears that you already have this item on you list. Would you like to update it? ";

		// Create a menu function here
		menuMaker existingMenu("It appears that you already have this item on you list. Would you like to update it?",
								"Yes",
								"No");
		existingMenu.prompt();
		int existingResponse = existingMenu.getResponse();

		if (existingResponse == 1) {
			std::cout << "Type in the unit type";
			std::cin >> tempType;
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
		realItem++;
	}

}

void List::removeItem() {
	int i = 0;
	bool found = false;
	std::string tempItemName;

	std::cout << "Type in the name of the product you wish to remove: ";
	std::getline(std::cin, tempItemName);

	while (i < itemCount || !found){
		// If the item is found in the list notify user
		if (groceryList[i] == tempItemName) {
			found = true;
		}
		else {
			i++;
		}
	}

	if (found) {
		// Set the values stored in that section to all be NULL
		groceryList[i].setItemName("");
		groceryList[i].setUnitType("");
		groceryList[i].setQuantity(0);
		groceryList[i].setPrice(0);

		realItem--;
	}
	else {
		std::cout << "That item does not appear to be in your list, try again with a modified name" << std::endl;
	}

}

void List::displayList() {

}

void List::printItem() {
	int i = 0;
	while (groceryList[i].getItemName() != "") {
		std::cout << "Item:      " << groceryList[i].getItemName() 	<< std::endl;
		std::cout << "Unit Type: " << groceryList[i].getUnitType() 	<< std::endl;
		std::cout << "Quantity:  " << groceryList[i].getQuantity() 	<< std::endl;
		std::cout << "Price:     " << groceryList[i].getPrice()		<< std::endl;
		std::cout << "\n----------------------------------------\n"		<< std::endl;

	}

}

void List::listCleanUp() {

}
