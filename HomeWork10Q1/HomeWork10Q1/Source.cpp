/*
Homework 9

This program will let the user build an inventory of a store and see/update things such as price, amount in stock, and order more items

Introduction to Computer Science.

Question 1.

Yosef Schoen

12/31/17
*/


#include <iostream>
#include <cstring>
using namespace std;

//assign names to the switch function in the main
enum Settings {Exit = 0, AddItem, FindPrice, Sold, Order, Print};

//the structure with all the needed information for the program
struct Item {
	int code;
	char name[20];
	int amount;
	int minamount;
	float price;
};

//this function will allow the user to add new items to the store
void addItem(Item * &store, int maxItems, int &numItems) {

	//these variables will be used to set the value of the variables in the structure
	int code;
	char name[20];
	int amount;
	int min;
	float price;

	//user assigning values to the item 
	cout << "enter code:\n";
	cin >> code;
	cout << "enter name:\n";
	cin >> name;
	cout << "enter amount:\n";
	cin >> amount;
	cout << "enter minimun amount:\n";
	cin >> min;
	cout << "enter price:\n";
	cin >> price;

	//making sure the user doesn't go over the maximum number of allowed items
	if (numItems == maxItems) {
		cout << "ERROR\n";
		return;
	}

	//this loop will check to see if the item already exists
	for (int i = 0; i < numItems; i++) {
		//if the item code and name are inputed as a new item the user can add the amount in stock
		if (store[i].code == code && store[i].name == name) {
			store[i].amount = store[i].amount + amount;
		}

		//if the item code is the same but the name is not it will say error
		else if (store[i].code == code && store[i].name != name) {
			cout << "ERROR\n";
		}
	}

	//creating a temporary array to hold every thing and allocate new space to the array
	Item* holder = new Item[numItems + 1];
	for (int i = 0; i < numItems; i++) {
		holder[i] = store[i];
	}

	//placing every thing in the new temporary holder
	holder[numItems].code = code;
	strcpy_s(holder[numItems].name, 20, name);
	holder[numItems].amount = amount;
	holder[numItems].minamount = min;
	holder[numItems].price = price;

	//freeing up memory in the store and placing every thing from the holder back in to the store
	delete[] store;
	store = holder;
	numItems++;

}

//this function will tell the user the price of the item based on the item code the user inputed
void findPrice(Item * store, int numItems) {
	int code;

	cout << "enter code:\n";
	cin >> code;

	for (int i = 0; i < numItems; i++) {
		if (store[i].code == code) {
			cout << "price: " << store[i].price << endl;
			return;
		}
	}
	//if item not found then it will say error
	cout << "ERROR\n";
	return;
}

//function to update the amount of items in stock afer a sale
int sold(Item * store, int &numItem) {
	int code;
	int amount;

	cout << "enter code:\n";
	cin >> code;
	cout << "enter amount\n";
	cin >> amount;

	for (int i = 0; i < numItem; i++) {
		if (store[i].code == code) {
			store[i].amount = store[i].amount - amount;
			return 0;
		}
	}

	//if item not found it will say error
	cout << "ERROR\n";
	return 0;
}

//function to order more items if the amount in stock is less than the minimum that should be in stock
void order(Item * store, int &numItems) {
	for (int i = 0; i < numItems; i++) {
		if (store[i].amount < store[i].minamount) {
			cout << "item name: " << store[i].name << endl
				 << "code: " << store[i].code << endl
				 << "amount to order: " << store[i].minamount + 5 - store[i].amount << endl;

			store[i].amount = store[i].minamount + 5;
		}
	}
}

//function to print all the data for every item in the store
void print(Item *store, int &numItems) {
	for (int i = 0; i < numItems; i++) {
		cout << "name: " << store[i].name << endl
			 << "code: " << store[i].code << endl
			 << "amount: " << store[i].amount << endl
			 << "minimun amount: " << store[i].minamount << endl
			 << "price: " << store[i].price << endl;
	}
}


int main() {
	//store will point to the structure above
	Item * store;
	int maxItems;
	int numItems = 0;
	//choice will be used for the switch function
	int choice;

	//user must let the system know the number of maximum items
	cout << "enter max number of items: " << endl;
	cin >> maxItems;

	//setting the array of items in the store to have at most the maximum number the user inputed
	store = new Item[maxItems];

	do {
		cout << "enter 0-5:\n";

		cin >> choice;

		//the choice numbers 0-5 have been replaced with the things that choice does, the values were declared above with the enum
		switch (choice) {
		//case Exit (0) will end the program
		case Exit:	break;
		
		//case AddItem will use the addItem function to add more things to the store
		case AddItem:	addItem(store, maxItems, numItems);
			break;

		//case FindPrice will use the findPrice function to tell the user the price of an item
		case FindPrice: findPrice(store, numItems);
			break;
		
		//case Sold will use the sold function to update the stock of an item which was sold
		case Sold:	sold(store, numItems);
			break;

		//case Order will use the order function to order more items if the amount goes below the minimum required ammount
		case Order:	order(store, numItems);
			break;

		//case Print will use the print function to Print all info about every item in the store
		case Print: print(store, numItems);
			break;
		
		//will display error if another thing was inputted other than numbers 1-5
		default: cout << "ERROR" << endl;
		}
	
	} while (choice != 0);

	return 0;
}
