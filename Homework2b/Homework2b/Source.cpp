/*
Homework 2

This program will take two numbers from the user and add, subtract, multiply, and divide them.

Introduction to Computer Science.

Question 6.

Yosef Schoen.

26/10/17.
*/




#include <iostream>
using namespace std;

int main() {

	//These are the 3 variables requested.
	int num1;
	int num2;

	cout << "enter two numbers: \n";

	//The user will now assign values to the variables.
	cin >> num1
		>> num2;

	//The program will now take the two variables and add, subtract, multiply, and divide them.
	cout << num1 << "+" << num2 << "=" << num1 + num2 << endl
		 << num1 << "-" << num2 << "=" << num1 - num2 << endl
		 << num1 << "*" << num2 << "=" << num1 * num2 << endl
		 << num1 << "/" << num2 << "=" << (num1 / 1.0) / num2 << endl;

	return 0;
}