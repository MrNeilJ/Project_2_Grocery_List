//
// Created by Neil on 4/25/2017.
//
#include <iostream>
#include <cstring>
#include "List.hpp"
#include "menuMaker.hpp"

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
	std::cin >> tempItemName;

	std::cout << "Type in the unit type: ";
	std::cin >> tempType;

	std::cout << "Type in the quantity in which you wish to buy: ";
	std::cin >> tempQuantity;

	std::cout << "Type in the price of each separate item: ";
	std::cin >> tempPrice;

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

			int replaceChoice = -1;
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
    int i = 0;

    std::cout << "Type in the name of the item that you are looking to remove" << std::endl;
    std::cin >> tempString;

    Item tempItem(tempString);

    while ((!found || groceryList[i].getItemName() != "") && i < arraySize) {
        if (groceryList[i] == tempItem) {
            found = true;
			std::cout << groceryList[i].getItemName() << " was removed." << std::endl;
			groceryList[i].blankItem();
			realItem--;

			// Organize the list to make sure all blank items are at the end of the array.
			listOrganize();

			// Shrink list if necessary and reorganize it
			listShrink();
        }
        else {
            i++;
        }
    }
    if (!found) {
        std::cout << "Could not find the item you were looking for, please try again. Thank you." << std::endl;
    }

}

/*
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
	while (i < arraySize || !found){
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
		groceryList[arraySize] = Item(tempItemName, tempType, tempQuantity, tempPrice);

		std::cout << tempItemName << " has been added. Thank you!" << std::endl;
		realItem++;
	}

}
*/
/*
void List::removeItem() {
	int i = 0;
	bool found = false;
	std::string tempItemName;

	std::cout << "Type in the name of the product you wish to remove: ";
	std::getline(std::cin, tempItemName);

	while (i < arraySize || !found){
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
*/

void List::displayList() {
	int i = 0;

	while (groceryList[i].getItemName() != "") {
		printItem(groceryList[i]);
		i++;
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
		arraySize += 4;
        Item* tempPtr = new Item[arraySize];
		int i = 0;


		// Add in items into the temp array
		while (groceryList[i].getItemName() != "") {
			tempPtr[i] = groceryList[i];
			i++;
		}
		// Create Blank items for the rest of the array
		for (i; i < arraySize; i++) {
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
	if (realItem % 4 == 0) {
		arraySize -= 4;
		Item* tempPtr = new Item[arraySize];
		int i = 0;

		// Add in items into the temp array
		while (groceryList[i].getItemName() != "") {
			tempPtr[i] = groceryList[i];
			i++;
		}
		// Create Blank items for the rest of the array
		for (i; i < arraySize; i++) {
			tempPtr[i] = Item();
		}
		// Delete old dynamically created array
		delete[]groceryList;

		// Add the array in the temp array to the original array
		groceryList = tempPtr;

		// Delete the temp pointer value
		delete[] tempPtr;
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

	delete[] tempPtr;
}
