/*
Homework 3

This program will allow the user to input 3 side lengths of a triangle
and say what kind of triangle it is.

Introduction to Computer Science.

Question 4.

Yosef Schoen

08/11/17
*/




#include <iostream>
using namespace std;

int main() {
	int sideA;
	int sideB;
	int sideC;

	cout << "enter 3 numbers\n";
	
	cin >> sideA
		>> sideB
		>> sideC;
	if ((sideA + sideB <= sideC) || (sideA + sideC <= sideB) || (sideB + sideC <= sideA)) {
		cout << "cannot form a triangle\n";
	}
	else if (sideA == sideB && sideA == sideC) {
		cout << "equilateral triangle\n";
	}

	else if ((sideA == sideB) || (sideA == sideC) || (sideB == sideC)) {
		cout << "isosceles triangle\n";
	}

	else if ((sideA != sideB) && (sideA != sideC) && (sideB != sideC)) {
		cout << "scalene triangle\n";
	}

	return 0;
}