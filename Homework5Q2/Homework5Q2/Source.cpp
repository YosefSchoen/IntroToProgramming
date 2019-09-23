/*
Homework 5

This program will show all perfect numbers under 500.

Introduction to Computer Science.

Question 2.

Yosef Schoen

22/11/17
*/





#include <iostream>
using namespace std;

//function to determin if x is perfect
bool perfect(int x) {
	int sum = 0;

	for (int i = 1; i < x; i++) {

		//factors of x are i with remainder zero
		if (x % i == 0) {
			sum = sum + i;
		}

	}

	return sum == x;

}

// function that lists all perfect numbers und 500
void PerfectList(int x = 500) {

	for (int i = 1; i < x; i++) {

		//calling first function to see which numbers under 500 are perfect
		if (perfect(i)) {
			cout << i << " ";
		}

	}

}

int main() {
	int a;

	cout << "enter a number:\n";

	cin >> a;

	//calling my perfect list function up to a
	PerfectList(a);

	cout << endl;

	//calling my perfect list function up to 500 
	PerfectList(500);


	return 0;
}