//
// Created by Neil on 4/25/2017.
//
#include <iostream>
#include <cstring>
#include "List.hpp"
#include "menuMaker.hpp"
#include "inputCheck.hpp"

/***************************************************
 * CONSTRUCTORS
 ***************************************************/
List::List() {
	// Creates a blank grocery list of 4 items.
	groceryList = new Item[4];
	arraySize = 4;
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

	// Expand list if necessary
	listExpand();

	// Build the item you want to add
	std::cout << "Type in the name of the product you wish to add: ";
	tempItemName = getString();

	std::cout << "Type in the unit type: ";
	tempType = getString();

	std::cout << "Type in the quantity in which you wish to buy: ";
	tempQuantity = getInt();

	std::cout << "Type in the price of each separate item: ";
	tempPrice = getFloat();

	// Create item
	Item tempItem(tempItemName, tempType, tempQuantity, tempPrice);

	// Check to see if the item already exists in current array
	while (!found || groceryList[i].getItemName() == "") {
		if(groceryList[i] == tempItem) {
			found = true;

			std::cout << "Looks like this item already exists." << std::endl;
			std::cout << "OLD ITEM:" << std::endl;
			printItem(groceryList[i]);

			std::cout << "NEW ITEM:" << std::endl;
			printItem(tempItem);

			menuMaker replaceMenu(	"What would you like to do with this item?",
									"Update with my new information",
									"Leave original information intact");

			int replaceChoice;
			do {
				replaceMenu.prompt();
				replaceChoice = replaceMenu.getResponse();

				if (replaceChoice == 1) {
					std::cout << "Sounds good, information has been updated. Thank you!" << std::endl;
					groceryList[i] = tempItem;
				}
				else if (replaceChoice == 2) {
					std::cout << "Okay, we will keep the original information. Thank you!" << std::endl;
				}
				else {
					std::cout << "I do not comprehend that response, please try a different option" << std::endl;
				}
			} while (replaceChoice < 1 && replaceChoice > 2);
		}
		else if (groceryList[i].getItemName() == "") {
			// Set the grocery list item to the first blank area
			groceryList[i] = tempItem;
			// Note that an item has been added to the array
			realItem++;

			found = true;

			// If the item count is equal to the max array size, then resize the current array

		}
        else {
            i++;
        }
	}

}

void List::removeItem() {
    std::string tempString;
    bool found = false;

    std::cout << "Type in the name of the item that you are looking to remove" << std::endl;
    tempString = getString();

    Item tempItem(tempString);

	for (int i = 0; i < arraySize; i++){
		if (groceryList[i] == tempItem) {
			std::cout << groceryList[i].getItemName() << " was removed." << std::endl;
			groceryList[i].blankItem();
			realItem--;
			found = true;

			// Organize the list to make sure all blank items are at the end of the array.
			listOrganize();

			// Shrink list if necessary and reorganize it
			listShrink();
		}
	}
	if (!found) {
		std::cout << "Could not find the item you were looking for, please try again. Thank you." << std::endl;
	}

}


void List::displayList() {
	for (int i = 0;i < arraySize; i++){
		if (groceryList[i].getItemName() != "") {
			printItem(groceryList[i]);
		}
	}
}

void List::printItem(Item currentItem) {
	std::cout << "Item:      " << currentItem.getItemName() 	<< std::endl;
	std::cout << "Unit Type: " << currentItem.getUnitType() 	<< std::endl;
	std::cout << "Quantity:  " << currentItem.getQuantity() 	<< std::endl;
	std::cout << "Price:     " << currentItem.getPrice()		<< std::endl;
	std::cout << "\n----------------------------------------\n"		<< std::endl;

}

void List::listExpand() {
	// Check to see if the next item added would cause it to reach beyond the bounds of the array
	if (realItem % 4 == 0 && realItem != 0) {
		int prevArray = arraySize;
		arraySize += 4;
		Item *tempPtr = new Item[arraySize];

		// Add in items into the temporary array
		for (int i = 0; i < prevArray; i++) {
			tempPtr[i] = groceryList[i];
		}
		for (int i = prevArray; i < arraySize; i++) {
			tempPtr[i] = Item();
		}
		// Delete old dynamically created array
		delete[] groceryList;

		// Add the array in the temp array to the original array
		groceryList = tempPtr;
	}


}

void List::listShrink(){

	// Check to see if the next item added would cause it to reach beyond the bounds of the array
	if (realItem % 4 == 0 && realItem != 0) {
		arraySize -= 4;
		Item* tempPtr = new Item[arraySize];

		for (int i = 0; i < arraySize; i++) {
			tempPtr[i] = groceryList[i];
		}

		// Delete old dynamically created array
		delete[]groceryList;

		// Add the array in the temp array to the original array
		groceryList = tempPtr;

	}
}

void List::listOrganize() {
	int blankCount = 0;
	int itemCount = 0;
	Item* tempPtr = new Item[arraySize];

	for(int i = 0; i < arraySize; i++) {
		if (groceryList[i].getItemName() != ""){
			tempPtr[itemCount] = groceryList[i];
			itemCount++;
		}
		else {
			blankCount++;
		}
	}
	for (int i = realItem ; i < arraySize; i++) {
		tempPtr[i] = Item();
	}
	delete[]groceryList;

	groceryList = tempPtr;

}

List::~List() {
	delete[]groceryList;
	groceryList = nullptr;

}
