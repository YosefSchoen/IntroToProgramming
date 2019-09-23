/*
Homework 5

This program will tell you the check sum of a social security number.

Introduction to Computer Science.

Question 3.

Yosef Schoen

22/11/17
*/




#include <iostream>
using namespace std;

// function to find some of digits larger than 9.
int SumDigits(int num) {

	int sum = 0;


	for (; num > 0; num = num / 10) {
		sum = sum + num % 10;
	}
	return sum;
}

// function to calculate the wieght of each digit and find the check some
int CheckSum(int num) {


	int SumNumbers = 0;

	//finding the digits by take the mod 10 of the whole number
	for (int i = 1; i <= 8; i++) {
		int digit = num % 10;

		//even place digits get a wieght of 2
		if (i % 2 == 1) {
			digit = digit * 2;
		}

		//odd placre digits get a wieght of 1
		else if (i % 2 == 0) {
			digit = digit;

		}

		//setting up the users number to restart the proccess
		num = num / 10;

		//finding the check sum according to the given method
		SumNumbers = SumNumbers + SumDigits(digit);
	}


	return 10 - (SumNumbers % 10);

}


int main() {

	int id;

	cout << "enter your ID:\n";

	cin >> id;

	cout << "your full ID is: " << id << CheckSum(id);


	return 0;
}
