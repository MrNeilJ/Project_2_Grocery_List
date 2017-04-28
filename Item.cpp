//
// Created by Neil on 4/25/2017.
//

#include "Item.hpp"
#include <cstring>


/***************************************************
 * CONSTRUCTORS
 ***************************************************/
Item::Item() {
	itemName 	= "";
	unitType 	= "";
	quantity 	= 0;
	price 		= 0;
}

Item::Item(std::string userStr) {
    itemName    = userStr;
    unitType    = "";
    quantity    = 0;
    price       = 0;
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

bool Item::operator==(const Item& rhs) {
	if (this->itemName == rhs.getItemName()){
		return true;
	}
	else {
		return false;
	}
}

/***************************************************
 * GETTERS
 ***************************************************/

std::string Item::getItemName() const {
	return itemName;
}
std::string Item::getItemName() {
	return itemName;
}

std::string Item::getUnitType() {
	return unitType;
}

int Item::getQuantity() {
	return quantity;
}

double Item::getPrice() {
	return price;
}

void Item::blankItem() {
    itemName 	= "";
    unitType 	= "";
    quantity 	= 0;
    price 		= 0;
}




