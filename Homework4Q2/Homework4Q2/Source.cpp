/*
Homework 4

This program will allow the user to input 2 numbers and then a list of numbers whose sum is less than the fisrt number,
or the amount of numbers in the list is less than the 2nd number

Introduction to Computer Science.

Question 2.

Yosef Schoen

015/11/17
*/




#include <iostream>
using namespace std;

int main() {

	//Declaring both inputs, the list value and the sum of list value
	int num1;
	int num2;
	int sum = 0;
	int list;

	cout << "enter 2 positive numbers:\n";

	cin >> num1;
	
	//setting a condition to make the user input a positive number for num1
	while (num1 <= 0) {
		cout << "ERROR\n";
		cin >> num1;
	}

	cin >> num2;

	//setting a condition to make the user input a positive number for num1
	while (num2 <= 0) {
		cout << "ERROR\n";
		cin >> num2;
	}

	cout << "enter a list of numbers\n";

	//this loop will allow the user to input more numbers in a list until its sum is equal to num1 or the amount of numbers is equal to num2
	for (int i = 0; (i < num2) && (sum < num1); i++) {
		cin >> list;
		sum = sum + list;
	}

	return 0;
}