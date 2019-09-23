/*
Homework 2

This Program will let the user pick to numbers, display them and then swap them.

Introduction to Computer Science.

Question 5

Yosef schoen

26/10/17
*/




#include <iostream>
using namespace std;

int main() {

	//These are the two variables requested.
	int x;
	int y;

	cout << "enter two numbers: \n";

	//The user will now decide the value of these variables.
	cin >> x
		>> y;

	//The program will now show the value of the variables.
	cout << "x=" << x << " ,y=" << y << endl;

	//The program will now swap these to values.
	int z = x;
	x = y;
	y = z;

	cout << "x=" << x << " ,y=" << y << endl;

	return 0;
}