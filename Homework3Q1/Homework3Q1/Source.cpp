/*
Homework 3

This program will take a number from the user and determin if its digits are even or odd.  Then it will multiply or add them.

Introduction to Computer Science.

Question 1.

Yosef Schoen.

8/11/17.
*/

#include <iostream>
using namespace std;

int main() {

	//declaring all my variables
	int onesP;
	int tensP;
	int num;

	cout << "enter a number:\n";
	
	cin >> num;

	//isolating the ones placeand the tens place
	onesP = num % 10;
	tensP = num / 10;

	//setting a max at 100
	if (num >= 100) {
		cout << "ERROR\n";
	}

	//checking if both digits are odd
	else if (onesP % 2 != 0 && tensP % 2 != 0) {
		cout << "odd digits only\n"
			<< onesP + tensP
			<< endl;
	}

	//checking if both digits are even
	else if (onesP % 2 == 0 && tensP % 2 == 0) {
		cout << "even digits only\n"
			<< onesP * tensP
			<< endl;
	}

	//checking if there is one even and one odd digit
	else if (onesP % 2 == 0 || tensP % 2 == 0) {
		cout << "mixed number\n";
	}

	return 0;
}