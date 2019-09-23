/*
Homework 5

This program will tell you the area of a rectangle and a circle.

Introduction to Computer Science.

Question 1.

Yosef Schoen

22/11/17
*/




#include <iostream>
using namespace std;

// function for area of a rectangle
int area(int x, int y) {
	return x * y;
}

// function for area of a circle
float area(int x) {
	return x * x * 3.14159;
}

int main() {
	int length;
	int width;
	int radius;

	cout << "enter length and width of the rectangle:\n";

	cin >> length >> width;

	//not allowing negative lengths
	while (length <= 0 || width <= 0) {
		cout << "ERROR\n";

		cin >> length >> width;
	}

	// calling the function for are of a rectangle
	cout << area(length, width) << endl;

	cout << "enter radius of the circle:\n";

	cin >> radius;

	// not allowing negative lengths
	while (radius <= 0) {
		cout << "ERROR\n";

		cin >> radius;
	}

	// calling function for area of a circle
	cout << area(radius) << endl;

	return 0;
}