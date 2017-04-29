/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.30.2017
 *
 * Description: This is the Item class for our grocery program.
 * In this class we are able to create Item object that host
 * information about their name, unitType, quantity, and price.
 * We are able to pull indiviual pieces of information from them
 * or even print them out in an easy to read format.
**************************************************************/


#include "Item.hpp"
#include <cstring>


/***************************************************
 * CONSTRUCTORS
 ***************************************************/
/**************************************************************
*                  Item::Item
* Description: Constructor function that saves the initial
* information of the Item object, setting all values to be
* blank. Used for filling up dead space in array.
**************************************************************/
Item::Item() {
	itemName 	= "";
	unitType 	= "";
	quantity 	= 0;
	price 		= 0;
}

/**************************************************************
*                  Item::Item
* Description: Constructor function that saves the initial
* information of the Item object, setting all values to be
* blank  except the name. Used when comparing our search.
**************************************************************/
Item::Item(std::string userStr) {
    itemName    = userStr;
    unitType    = "";
    quantity    = 0;
    price       = 0;
}

/**************************************************************
*                  Item::Item
* Description: Constructor function that savs the initial
* information of the Item object, setting all values to be
* whatever the user inputs.
**************************************************************/
Item::Item(std::string userItem, std::string userType, int userQuantity, double userPrice) {
	itemName 	= userItem;
	unitType 	= userType;
	quantity 	= userQuantity;
	price 		= userPrice;
}


/***************************************************
 * SETTERS
 ***************************************************/
/**************************************************************
*                  Item::setItemName
* Description: Sets the itemName value to be whatever the
* user types in
**************************************************************/
void Item::setItemName(std::string userName) {
	itemName = userName;
}

/**************************************************************
*                  Item::setUnitType
* Description: Sets the unitType value to be whatever the
* user types in
**************************************************************/
void Item::setUnitType(std::string userType) {
	unitType = userType;
}

/**************************************************************
*                  Item::setQuantity
* Description: Sets the quantity value to be whatever the
* user types in
**************************************************************/
void Item::setQuantity(int userQuantity) {
	quantity = userQuantity;
}

/**************************************************************
*                  Item::setPrice
* Description: Sets the price value to be whatever the
* user types in
**************************************************************/
void Item::setPrice(double userPrice) {
	price = userPrice;
}

/**************************************************************
*                  Item::operator==
* Description: modifies what "==" does.  This will compare two
* objects names and confirm that they are the same.
**************************************************************/
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
/**************************************************************
*                  Item::getItemName
* Description: Returns the value stored in itemName
**************************************************************/
std::string Item::getItemName() const {
	return itemName;
}

/**************************************************************
*                  Item::getItemName
* Description: Returns the value stored in itemName
**************************************************************/
std::string Item::getItemName() {
	return itemName;
}

/**************************************************************
*                  Item::getUnitType
* Description: Returns the value stored in unitType
**************************************************************/
std::string Item::getUnitType() {
	return unitType;
}

/**************************************************************
*                  Item::getQuantity
* Description: Returns the value stored in quantity
**************************************************************/
int Item::getQuantity() {
	return quantity;
}

/**************************************************************
*                  Item::getPrice
* Description: Returns the value stored in price
**************************************************************/
double Item::getPrice() {
	return price;
}

/**************************************************************
*                  Item::blankItem
* Description: modifies the object so all the values inside of
* it are blank. Used when removing items from the list.
**************************************************************/
void Item::blankItem() {
    itemName 	= "";
    unitType 	= "";
    quantity 	= 0;
    price 		= 0;
}




