#pragma once
#include <string>
using namespace std;


class GroceryItem
{
public:
	//Constructor - empty item with quantity 0
	GroceryItem();
	//Constructor -  initializes empty item with quantity 0
	GroceryItem(const std::string& name);
	//Constructor -  initializes an item with a spacified quantity
	GroceryItem(const std::string& name, int quantity);

	//Getters
	std::string getName() const;
	int getQuantity() const;


	//Increase quantity
	void addItem();
	//Decreases quantity
	void removeItem();
	//Updates quantity
	void updateCount();
	//Display histogram
	void itemHistogram() const;
	//Search for item
	void itemSearch();


private:
	//Grocery items name
	std::string name;
	//Item quantity
	int quantity;
};

