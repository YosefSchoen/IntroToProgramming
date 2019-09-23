/*
Homework 3

This program will allow the user to enter a date and show what the day of the week it fell out on

Introduction to Computer Science.

Question 5.

Yosef Schoen

08/11/17
*/


#include <iostream>
using namespace std;

int main() {

	//declaring variables
	int year;
	int day;
	int month;
	char helpChar;

	cout << "enter a date:\n";

	cin >> day >> helpChar >> month >> helpChar >> year;

	//given algorithim to find day of week
	int b = year / 4;
	int c = year + b;	
	int d;

	switch (month) {
		case 1: d = 1; break;
		case 2: d = 4; break;
		case 3: d = 4; break;
		case 4: d = 0; break;
		case 5: d = 2; break;
		case 6: d = 5; break;
		case 7: d = 0; break;
		case 8: d = 3; break;
		case 9: d = 6; break;
		case 10: d = 1; break;
		case 11: d = 4; break;
		case 12: d = 6; break;
	}

	int e = c + d;
	int f = ((e + day) % 7); 
	
	//listing days of the week
	if (f == 1) {
		cout << "Sunday\n";
	}


	else if (f == 2) {
		cout << "Monday\n";
	}


	else if (f == 3) {
		cout << "Tuesday\n";
	}

	else if (f == 4) {
		cout << "Wednesday\n";
	}

	else if (f == 5) {
		cout << "Thursday\n";
	}


	else if (f == 6) {
		cout << "Friday\n";
	}

	else if (f == 0) {
		cout << "Saturday\n";
	}

	return 0;
}