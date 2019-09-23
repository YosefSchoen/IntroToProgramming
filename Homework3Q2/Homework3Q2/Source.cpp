/*
Homework 3

This program will allow the user to input 3 numbers
and determine which number is smallest, largest, and in between.

Introduction to Computer Science,

Question 2.

Yosef Schoen

08/11/17
*/



#include <iostream>
using namespace std;

int main() {

	//declaring my variables
	int first;
	int last;
	int number;

	cout << "enter 3 numbers:\n";
	cin >> first
		>> last
		>> number;

	//setting the range of valid inputs
	if (number >= 100 || number <= 0) {
		cout << "ERROR\n";
	}

	//determining if the number is the smallest one
	else if (number < first) {
		cout << "smaller\n";
	}

	//determining if the number is the largest one
	else if (number > last) {
		cout << "bigger\n";
	}

	//determining if the number is in between
	else if (number >= first && number <= last) {
		cout << "between\n";
	}

	return 0;
}