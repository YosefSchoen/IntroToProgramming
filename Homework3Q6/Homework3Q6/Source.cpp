/*
Homework 3

This program will allow the user to input 3 numbers and will rearange them in order

Introduction to Computer Science.

Question 6.

Yosef Schoen

08/11/17

*/


#include <iostream>
using namespace std;

int main() {

	int num1, num2, num3, smallest, middle, biggest;

	cout << "enter 3 numbers:\n";

	cin >> num1
		>> num2
		>> num3;

	//looking for smallest number
	if ((num1 < num2) && (num1 < num3)) {
		smallest = num1;
	}

	else if ((num2 < num1) && (num2 < num3)) {
		smallest = num2;
	}

	else if ((num3 < num1) && (num3 < num2)) {
		smallest = num3;
	}

	//looking for middle number
	if ((num1 > num2) ^ (num1 > num3)) {
		middle = num1;
	}

	else if ((num2 > num1) ^ (num2 > num3)) {
		middle = num2;
	}

	else if ((num3 > num1) ^ (num3 > num2)) {
		middle = num3;
	}

	// looking for largest number
	if ((num1 > num2) && (num1 > num3)) {
		biggest = num1;
	}

	else if ((num2 > num1) && (num2 > num3)) {
		biggest = num2;
	}

	else if ((num3 > num1) && (num3 > num2)) {
		biggest = num3;
	}

	cout << smallest << " "
		 << middle << " "
		 << biggest << " "
		 << endl;

	return 0;
}