//
// Created by Neil on 4/25/2017.
//

#ifndef PROJECT_2_LIST_HPP
#define PROJECT_2_LIST_HPP


#include "Item.hpp"

class List {
private:
	Item* groceryList;
	int itemCount;

public:
	// Constructors
	List();

	// Member Functions
	void addItem(std::string, std::string, int, double);
	void removeItem();
	void displayList();
	void printItem();





};


#endif //PROJECT_2_LIST_HPP
