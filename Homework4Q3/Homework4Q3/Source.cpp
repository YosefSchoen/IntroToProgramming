/*
Homework 4

This program will show the fibonacci sequence up to the number of terms that the user inputs.

Introduction to Computer Science.

Question 3.

Yosef Schoen

015/11/17
*/

#include <iostream>
using namespace std;

int main() {

	int ListSize;
	cout << "enter a number\n";

	cin >> ListSize;

	//making sure the user inputs a number bigger than zero
	while (ListSize < 0) {
		cout << "ERROR\n";

		cin >> ListSize;
	}

	//first 2 terms in the sequence and the rule to find the next term
	int fib0 = 0;
	int fib1 = 1;
	int fibN = fib0 + fib1;

	cout << fib0 
		 << " "
		 << fib1
		 << " ";

	for (int i = 1; i < ListSize; i++) {
		
		fibN = fib0 + fib1;
		fib0 = fib1;
		fib1 = fibN;
		
		//printing the list to the screen with a space
		if (i < ListSize) {
			cout << fibN << " ";
		}

		//printing the last number without a space
		else {
			cout << fibN << endl;
		}

	}


	return 0;
}