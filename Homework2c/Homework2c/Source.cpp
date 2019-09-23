/*
Homework 2.

This program will take a three digit number from the user, and add up its digits.

Introduction to Computer Science.

Question 7.

Yosef Schoen.

26/10/17.
*/




#include <iostream>
using namespace std;

int main() {

	//The program need a variable for the user to use.
	int num;

	//The user will be asked to pick a three digit number.
	cout << "enter a three digit number: \n";

	//The user will now asign a value to the variable
	cin >> num;

	/*A new variable x will be used to extract the value of hundreds place of the original variable, and then subtracted that value times 100
	from the number the user picked.
	For example if user picks 152, int x will be 1.  then we multiply x by 100 and subtracted 100 from 152.
	This will leave us with num = 52, and x will equal 1.*/
	int x = num / 100;
	num = num - (100 * x);

	//A new variable y will do the same as x but in the tens place instead of the hundreds.
	int y = num / 10;
	num = num - (10 * y);

	//Now we can add x and y and the original number which only has the ones place remaining.
	cout << "the sum is: "
		<< x + y + num
		<< endl;

	return 0;
}