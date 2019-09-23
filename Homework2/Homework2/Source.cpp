/*
Homework 2

This program will allow the user to input to numbers
and out put a new number with the formula
asked for in the homework question.

Introduction to Computer Science,

Question 4.

Yosef Schoen

26/10/17
*/




#include <iostream>
using namespace std;

int main() {

	//These are the 3 variables requested.
	int a;
	int b;
	float c;

	cout << "enter two numbers: \n";

	//The user will pick numbers for the first to variables.
	cin >> a
		>> b;

	//The program will now solve for the 3rd variable
	c = (5.0 * a + 3) / (6 * b + 2);

	//Finally it will print the value of the 3rd variable
	cout << "c="
		<< c
		<< endl;

	return 0;
}