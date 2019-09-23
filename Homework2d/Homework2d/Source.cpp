/*
Homework 2.

This Program will calculate the remaining flight time of a passanger in the HH:MM:SS format.

Introduction to Computer Science.

Question 8.

Yosef Schoen.

26/10/17.
*/




#include <iostream>
using namespace std;

int main() {

	//These are the variables the user will need.
	int tHours;
	int tMinutes;
	int tSeconds;

	int dHours;
	int dMinutes;
	int dSeconds;

	cout << "enter flight takeoff:\n";
	
	//The user will now enter the take off time in HH:MM:SS format.
	cin >> tHours
		>> tMinutes
		>> tSeconds;

	cout << "enter flight duration:\n";

	//The user will now enter the flight duraton in HH:MM:SS format.
	cin >> dHours
		>> dMinutes
		>> dSeconds;

	/*Now the program will tell the user the time of the flight arrival.
	Please note time is measured in base 60, so i had to convert the minutes and seconds to run according to that system.*/
	cout << "flight arrival is:\n"
		 << ((tHours + dHours) + ((tMinutes + dMinutes) / 60)) % 24 << ":"
		 << ((tMinutes + dMinutes) % 60) + ((tSeconds + dSeconds) / 60) << ":"
		 << (tSeconds + dSeconds) % 60
		 << endl;


	return 0;
}