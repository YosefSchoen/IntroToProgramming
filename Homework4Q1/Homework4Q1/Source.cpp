/*
Homework 4

This program will input 10 random numbers and determine if they are sorted or not

Introduction to Computer Science.

Question 1.

Yosef Schoen

015/11/17
*/


//need ctime to create a psuedo random number seed
#include <ctime>
#include <iostream>
using namespace std;

int main() {

	srand(time(nullptr));
	int num;
	int previous = 0;
	bool sorted = true;


	for (int i = 0; i < 10; i++) {
		//making all random numbers less than or equal to 1000
		num = rand() % 1000 + 1;
		
		//prints a space after number unless its the last number on the list
		if (i < 9) {
			cout << num << " ";
		}

		//if the number is the last one on the list do not put a space after
		else {
			cout << num << endl;
		}

		//boolean condition to determine if list is sorted
		if (num < previous) {
			sorted = false;		
		}

		previous = num;
	}

	//display for sorted list
	if (sorted) {
		cout << "sorted list\n";
	}

	//display for unsorted list
	else {
		cout << "not sorted list\n";
	}

	return 0;
}