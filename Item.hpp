//
// Created by Neil on 4/25/2017.
//

#ifndef PROJECT_2_ITEM_HPP
#define PROJECT_2_ITEM_HPP

#include <iostream>
class Item {
private:
	std::string 	itemName;	// Name of the product
	std::string 	unitType;	// Type of measurement (box, ounce, pound, bag, etc.)
	int 			quantity;	// Amount the user wants
	double 			price;		// Price per unit

public:

	// Constructors
	Item();
	Item(std::string);
	Item(std::string, std::string, int, double);

	// Setter Functions
	void setItemName(std::string userName);
	void setUnitType(std::string userType);
	void setQuantity(int userQuantity);
	void setPrice(double userPrice);

	// Getter Functions
	std::string getItemName() const;
	std::string getItemName();
	std::string getUnitType();
	int getQuantity();
	double getPrice();

	// Operator Overloading for the "==" operator
	bool operator==(const Item&);

	// Array re-designers
	void blankItem();


};


#endif //PROJECT_2_ITEM_HPP
