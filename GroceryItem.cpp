#include "GroceryItem.h"
#include <iostream>

//Constructer
GroceryItem::GroceryItem()
	:name(""), quantity(0) {}
GroceryItem::GroceryItem(const std::string& name)
	:name(name), quantity(0) {}
GroceryItem::GroceryItem(const std::string& name, int quantity)
	:name(name), quantity(quantity){}

//Getters
std::string GroceryItem::getName() const {
	return name;
}

int GroceryItem::getQuantity() const {
	return quantity;
}

//Increse quantity by 1
void GroceryItem::addItem() {
	quantity++;
}
//Decrease quantity by 1
void GroceryItem::removeItem() {
	if (quantity > 0) {
		quantity--;
	}
}
//Update count 
void GroceryItem::updateCount() {
	quantity++;
}

//print histogram
void GroceryItem::itemHistogram() const {
	//loop
	for (int i = 0; i < quantity; ++i) {
		//prints asterisk
		std::cout << "*";
	}
}

