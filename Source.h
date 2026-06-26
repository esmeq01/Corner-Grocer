#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include "GroceryItem.h"

using namespace std;

class Source
{
public:
	//loads inventory from file and writes backup file 
	void createBackupFile(const string& filename, std::map<string, GroceryItem>& items) {
		//opens input file
		ifstream inFS;
		inFS.open("inventory.txt");
		//checks if input file was opened successfully
		if (!inFS.is_open()) {
			cout << "Error.Could not open file inventory.txt" << std::endl;
			return;
		}
		string name;

		while (inFS >> name) {
			//Capitalize first letter 
			name[0] = toupper(name[0]);
			items[name].updateCount();
		}
		//closes input file
		inFS.close();

		//Write frequency data to output file
		ofstream outFS;
		//checks if output file was opened successfully
		outFS.open("frequency.dat");
		if (!outFS.is_open()) {
			cout << "Error.Could not open file frequency.dat" << std::endl;
			return;
		}
		//writes item and quantity to output file
		for (const auto& pair : items) {
			outFS << pair.first << " " << pair.second.getQuantity() << endl;
		}
		//closes output file
		outFS.close();
	}

	//Menu option 1 - Search item obtain numeric value
	void itemSearch(map<string, GroceryItem>& items) {
		string itemName;
		cout << "Enter item name: ";
		cin >> itemName;

		if (itemName.empty()) {
			cout << "Invalid item name." << endl;
			return;
		}
		//Capitalize first letter
		itemName[0] = toupper(itemName[0]);
		//if item was found 
		if (items.count(itemName) > 0) {
			cout << "Quantity of " << itemName << " purchased: "
				<< items.at(itemName).getQuantity() << endl;
		}
		else {
			//item not found
			cout << itemName << " is not part of inventory. Do you wish to add it? (y/n): ";
			char choice;
			cin >> choice;

			if (choice == 'y' || choice == 'Y') {
				addItem(itemName, items);
			}
			else if (choice == 'n' || choice == 'N') {
				cout << itemName << " was not added." << endl;
			}
			else {
				cout << "Invalid choice. Item was not added." << endl;
			}
		}
	}
	//add item to map
	void addItem(const string& itemName, map<string, GroceryItem>& items) {
		items.emplace(itemName, GroceryItem(itemName, 1));
		cout << itemName << " added with quantity 1." << endl;
		//append item to inventory file
		ofstream outFS("inventory.txt", ios::app);
		outFS << "\n" << itemName << endl;
	}

	//Menu option 2 - Obtain list with numeric value
	void itemListCount(map<string, GroceryItem>& items)const{
		//loop
		for (const auto& pair : items) {
			cout << pair.first << " " << pair.second.getQuantity() << endl;
		}
	}

	//Menu option 3 - Obtain histogram
	void itemHistogram(map<string, GroceryItem>& items)const {
		//loop
		for (auto it = items.begin(); it != items.end(); ++it) {
			//print item
			std::cout << it->first << " ";
			//prints histogram
			it->second.itemHistogram();
			//new line after item
			std::cout << std::endl;
		}
	}
};
