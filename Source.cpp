/*
*Name:Esmeralda Quiroz
*Date: 06/21/26
*Assignment: Project3 - Corner Grocer
*/

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "GroceryItem.h"
#include "Source.h"

using namespace std;

Source source;
//stores items in a map
map<string, GroceryItem>items;

//Print main menu to interface
void displayMenu() {
	cout << "*****************************************************************" << endl;
	cout << "******************* Welcome to Corner Grocer! *******************" << endl;
	cout << "Please select a menu option from below." << endl;
	cout << "1 - Returns numeric value for item's purchase frequency" << endl;
	cout << "2 - Prints inventory list with frequence of items purchased" << endl;
	cout << "3 - Prints frequncy information of items in a form of a histogram" << endl;
	cout << "4 - Exit" << endl;
	cout << "*****************************************************************" << endl;
}

void printMenu() {
	displayMenu();
}

//reads users input and verifies it is valid
unsigned int getMenuChoice(unsigned int maxChoice) {
	unsigned int choice = 0;
	while (true) {
		cin >> choice;   //user input 

		//User input invalid choice
		if (choice > maxChoice) {
			cout << "Invalid Choice.Please select a valid option form the menu (1-4)." << endl;
			continue;
		}
		//if valid choice is valid 
		if (choice >= 1 && choice <= maxChoice) {
			return choice;
		}
	}
}

//main loop
void mainMenu() {
	int choice = 0;
	
	while (choice != 4) { //loop runs as long as choice isn't 4
		displayMenu();
		choice = getMenuChoice(4); //Get users selection

		//option 1
		if (choice == 1) {
			source.itemSearch(items);
		}
		//option 2
		else if (choice == 2) {
			source.itemListCount(items);
		}
		//option 3
		else if (choice == 3) {
			source.itemHistogram(items);
		}
		//option 4
		else if (choice == 4) {
			cout << "Good Bye." << endl;
		}
	}
}

int main() {
	//loads data from file and creates backup copy
	source.createBackupFile("inventory.txt", items);
	mainMenu();
	return 0; //Program ran successfully
}
