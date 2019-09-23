/*
Homework 3

This program will allow the user to enter a number and show how many days on in that month.

Introduction to Computer Science.

Question 7.

Yosef Schoen

08/11/17
*/


#include <iostream>
using namespace std;

int main() {
	enum Month { JAN = 1, FEB, MARCH, APRIL, MAY, JUNE, JULY, AUG, SEPT, OCT, NOV, DEC };
	Month month;
	int input;

	int big = 31;
	int small = 30;
	int feb = 28;

	cout << "enter a number:\n";

	cin >> input;
	month = (Month)input;

	switch (month) {
	case 1: cout << big << " days in the month\n"; break;
	case 2: cout << feb << " days in the month\n"; break;
	case 3: cout << big << " days in the month\n"; break;
	case 4: cout << small << " days in the month\n"; break;
	case 5: cout << big << " days in the month\n"; break;
	case 6: cout << small << " days in the month\n"; break;
	case 7: cout << big << " days in the month\n"; break;
	case 8: cout << big << " days in the month\n"; break;
	case 9: cout << small << " days in the month\n"; break;
	case 10: cout << big << " days in the month\n"; break;
	case 11: cout << small << " days in the month\n"; break;
	case 12: cout << big << " days in the month\n"; break;
	}

	return 0;
}