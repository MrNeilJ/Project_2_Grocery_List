//
// Created by Neil on 4/25/2017.
//

#ifndef PROJECT_2_LIST_HPP
#define PROJECT_2_LIST_HPP


#include "Item.hpp"

class List {
private:
	Item* groceryList;
	int arraySize;
	int realItem;

public:
	// Constructors
	List();

	// Member Functions
	void addItem();
	void removeItem();
	void displayList();
	void printItem(Item);


    void listExpand();
	void listShrink();
	void listOrganize();
};


#endif //PROJECT_2_LIST_HPP
