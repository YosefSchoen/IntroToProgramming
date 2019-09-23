/*
Homework 3

This program will allow the user to input 2 numbers
and add, subtract, multiply, or divide them.

Introduction to Computer Science.

Question 3.

Yosef Schoen

08/11/17
*/

#include <iostream>
using namespace std;

int main() {

	//declaring variables
	int num1;
	int num2;
	char inOp;
	enum Op { ADD = '+', SUBTRACT = '-', MULTIPLY = '*', DIVIDE = '/'};
	Op op;

	cout << "enter 2 numbers:\n";
	
	cin >> num1
		>> num2;
	//the user will now pick an operator
	cout << "enter an operator:";

	cin >> inOp;
	op = (Op)inOp;

	//determing what will happen based on the operator selected
	switch (op) { 
		case ADD:
			cout << num1 << " + " << num2 << " = " 
				 << num1 + num2 << endl;
			break;
		case SUBTRACT:
			cout << num1 << " - " << num2 << " = " 
				 << num1 - num2 << endl;
			break;
		case MULTIPLY:
			cout << num1 << " * " << num2 << " = " 
				 << num1 * num2 << endl;
			break;
		case DIVIDE:
			cout << num1 << " / " << num2 << " = " 
				 << (num1 * 1.0) / num2 << endl;
			break;
		default: cout << "ERROR:\n";
		}

	return 0;
}