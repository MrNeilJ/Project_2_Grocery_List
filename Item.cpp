//
// Created by Neil on 4/25/2017.
//

#include "Item.hpp"
#include <cstring>


/***************************************************
 * CONSTRUCTORS
 ***************************************************/
Item::Item() {
	itemName 	= NULL;
	unitType 	= NULL;
	quantity 	= NULL;
	price 		= NULL;
}

Item::Item(std::string userItem, std::string userType, int userQuantity, double userPrice) {
	itemName 	= userItem;
	unitType 	= userType;
	quantity 	= userQuantity;
	price 		= userPrice;
}


/***************************************************
 * SETTERS
 ***************************************************/
void Item::setItemName(std::string userName) {
	itemName = userName;
}

void Item::setUnitType(std::string userType) {
	unitType = userType;
}

void Item::setQuantity(int userQuantity) {
	quantity = userQuantity;
}

void Item::setPrice(double userPrice) {
	price = userPrice;
}

bool Item::operator==(const std::string& rhs) {
	return strcmp(this->itemName, rhs);
}

/***************************************************
 * GETTERS
 ***************************************************/


