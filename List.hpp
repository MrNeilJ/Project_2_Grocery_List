/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.30.2017
 *
 * Description: This is the List header class in the grocery application.
 * This class does the majority of the work in this program.
 * In here we are able to dynamically create and resize a
 * list to whatever size necessary. We can then add and remove
 * items from the list as needed and even print out the list
 * in an easy to read format. We can even checkout using
 * the methods in this class
**************************************************************/

#ifndef PROJECT_2_LIST_HPP
#define PROJECT_2_LIST_HPP


#include "Item.hpp"
#include "inputCheck.hpp"


class List {
private:
	Item* groceryList;
	int arraySize;
	int realItem;

public:
	// Constructors
	List();						// Builds the original object for use

	// Member Functions
	void addItem();				// Adds an item to the list
	void removeItem();			// Removes an item from the list
	void displayList();			// Prints out the entire list
	void printItem(Item);		// Prints out a single item
    void listExpand();			// Adjusts the grocery list size to be larger
	void listShrink();			// Adjusts the grocery list size to be smaller
	void listOrganize();		// Removes any blank space from the list and puts it at the end
	void checkOut();			// Prints out the list and returns the total for how much they spent

	~List();					// Frees memory that was dynamically allocated
};


#endif //PROJECT_2_LIST_HPP
